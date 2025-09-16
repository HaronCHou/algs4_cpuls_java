#include <iostream>
#include <random>
#include "Percolation.h"

class PercolationStats{
public:
// 在N*N的grid进行T次独立计算实验，得到一个统计意义的均值和方差
    PercolationStats(int N, int T):mean(0.0), stddev(0.0), confidenceLo(0.0), confidenceHi(0.0)
    {
        std::random_device rd;  // 获取随机数种子
        std::mt19937 gen(rd()); // 使用生成器
        std::uniform_int_distribution<> dis(1, N); // 定义范围【1,N】
        int size = N*N;
        int times = T;
        thresholds = new float[times]; // T次实验的阈值
        // 进行T次实验
        std::cout << "grid:" << N << "," << T << "次\t";
        clock_t start, end;
        start = clock();
        for(int i = 0; i < times; i++)
        {
            int count = 0; // 记录open的site数
            Percolation pl(N);
            // 随机选一个site，然后该site有一定概率->open,p->open, （1-p）->close,每次open检查是否percolation。
            // std::cout << "the " << i+1 << " experiment..." << std::endl;
            do{
                int row = dis(gen) - 1;
                int col = dis(gen) - 1; // [0,N-1]
                if(pl.isOpen(row, col)){
                    continue;
                }
                pl.open(row, col);
                count++;
                // std::cout << "open site: (" << row << "," << col << ")" << std::endl;
            }while(!pl.percolates());
            float threash = (float)((float)count / (float)size); // 
            // std::cout << "the " << i+1 << " experiment threash is: " << threash << std::endl;
            thresholds[i] = threash;
        }
        end = clock();
        double duration = double(end - start) / CLOCKS_PER_SEC;
        std::cout << "cost=" << duration * 1000 / times << "ms     \t";
            
        // for (size_t i = 0; i < times; i++)
        // {
        //     std::cout << thresholds[i] << " ";
        // }
        
        mean = meanCalc();
        stddev = stddevCalc();
        confidenceLo = confidenceLoCalc();
        confidenceHi = confidenceHiCalc();
        std::cout << "mean = " << mean;
        std::cout << "\t stddev = " << stddev;
        std::cout << "\t 95% confidence interval = [" << confidenceLo << ", " << confidenceHi << "]" << std::endl;

    }
    ~PercolationStats(){
        delete[] thresholds;
    }
    float meanCalc(){
        float sum = 0.0;
        int size = sizeof(thresholds)/sizeof(thresholds[0]);
        for(int i = 0; i < size; i++)
            sum += thresholds[i];
        mean = sum / size;
        // std::cout << "mean is: " << mean << std::endl;
        return mean;
    }
    float stddevCalc(){
        if(mean == 0.0){
           mean =  meanCalc();
        }
        float sum = 0.0;
        int size = sizeof(thresholds)/sizeof(thresholds[0]);
        for(int i = 0; i < size; i++)
            sum += (thresholds[i] - mean) * (thresholds[i] - mean);
        stddev = sqrt(sum / (size - 1));
        // std::cout << "stddev is: " << stddev << std::endl;
        return stddev;
    }
    float confidenceLoCalc(){
        if(mean == 0.0){
           mean =  meanCalc();
        }
        if(stddev == 0.0){
            stddev = stddevCalc();
        }
        int size = sizeof(thresholds)/sizeof(thresholds[0]);
        confidenceLo = mean - (1.96 * stddev / sqrt(size));
        // confidenceHi = mean + (1.96 * stddev / sqrt(size));
        // std::cout << "confidenceLo is: " << confidenceLo << std::endl;
        return confidenceLo;
    }
    float confidenceHiCalc(){
        if(mean == 0.0){
           mean =  meanCalc();
        }
        if(stddev == 0.0){
            stddev = stddevCalc();
        }
        int size = sizeof(thresholds)/sizeof(thresholds[0]);
        // confidenceLo = mean - (1.96 * stddev / sqrt(size));
        confidenceHi = mean + (1.96 * stddev / sqrt(size));
        // std::cout << "confidenceLo is: " << confidenceLo << std::endl;
        return confidenceHi;
    }
private:
    float mean;
    float stddev;
    float confidenceLo;
    float confidenceHi; 
    float* thresholds; // T次实验的阈值
};

#if 0 // for test 10_1.txt
int main(int argc, char* argv[]){
    // 
    int N, T;
    while(std::cin >> N >> T)
    {
        PercolationStats pls(N, T);
    }

    return 0;
}

#else
int main(int argc, char* argv[]){
    // 
    int N, T;
    // while(std::cin >> N >> T)
    std::cin >> N >> T;
    PercolationStats pls(N, T);

    return 0;
}
#endif 