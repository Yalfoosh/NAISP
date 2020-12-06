#include <iostream>

#define M 5
#define N 4
#define range 2000


void printArray(uint16_t* problem, uint width, uint height) {
    for(auto i = 0; i < height; ++i) {
        for(auto j = 0; j < width; ++j)
            std::cout << problem[i * width + j] << " ";

        std::cout << std::endl;
    }
}

void print(uint16_t* problem, uint width, uint height, uint16_t* current) {
    if(problem != current) {
        if((current < problem + width) || (*(current - 1) < *(current - width)))
            print(problem, width, height, current - 1);
        else
            print(problem, width, height, current - width);
    }

    auto offset = current - problem;

    std::cout << "(" << offset / width << ", " << offset % width << ")" << std::endl;
}

void solve(uint16_t* problem, uint width, uint height) {
    for(auto i = 1; i < height; ++i)
        problem[i * width] += problem[(i - 1) * width];

    for(auto j = 1; j < width; ++j)
        problem[j] += problem[j - 1];

    for(auto i = 1; i < height; ++i)
        for(auto j = 1; j < width; ++j)
            problem[i * width + j] += std::min(problem[(i - 1) * width + j], problem[i * width + j - 1]);

    auto last = problem + width * height - 1;

    print(problem, width, height, last);
    std::cout << *last << std::endl;
}

int main() {
    srand(1208);
    auto printTheArray = false;

    auto problem = new uint16_t[M * N];

    for(auto i = 0; i < M; ++i)
        for(auto j = 0; j < N; ++j)
            problem[i * N + j] = rand() % range;

    if(printTheArray) {
        printArray(problem, N, M);
        std::cout << std::endl;
    }

    solve(problem, N, M);

    delete[] problem;

    return 0;
}
