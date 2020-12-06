/* This is not actually faster lmao */

#include <chrono>
#include <iostream>
#include <list>
#include <queue>
#include <set>

#define M 9
#define N 9
#define range 10

#define c_t std::chrono::high_resolution_clock::now()
#define ms std::chrono::duration_cast<std::chrono::milliseconds>


void printArray(uint16_t *problem, uint width, uint height) {
    for (auto i = 0; i < height; ++i) {
        for (auto j = 0; j < width; ++j)
            std::cout << problem[i * width + j] << " ";

        std::cout << std::endl;
    }
}

struct Node {
public:
    uint16_t* node;
    uint16_t cost;
    Node* parent;

    Node(uint16_t* node, const uint16_t& cost, Node* parent) {
        this->node = node;
        this->cost = cost;
        this->parent = parent;
    }
};

class NodeGreater{
public:
    bool operator()(Node* lhs, Node* rhs){
        return lhs->cost > rhs->cost;
    }
};

void print(uint16_t* problem, const uint& width, const uint& height, Node* last) {
    if(last->parent != nullptr)
        print(problem, width, height, last->parent);

    auto offset = last->node - problem;

    std::cout << "(" << offset / width << ", " << offset % width << ")" << std::endl;
}

std::list<uint16_t*> explore(const uint16_t* problem, const uint& width, const uint& height, uint16_t* current, const std::set<uint16_t*>& closed) {
    auto toExplore = std::list<uint16_t*>();

    auto offset = current - problem;
    auto i = offset / width;
    auto j = offset % width;

    if(i != 0 && closed.find(current - width) == closed.end())
        toExplore.emplace_back(current - width);

    if(i < (height - 1) && closed.find(current + width) == closed.end())
        toExplore.emplace_back(current + width);

    if(j != 0 && closed.find(current - 1) == closed.end())
        toExplore.emplace_back(current - 1);

    if (j < (width - 1) && closed.find(current + 1) == closed.end())
        toExplore.emplace_back(current + 1);

    return toExplore;
}

void solve(uint16_t *problem, const uint& width, const uint& height, const bool verbose = true) {
    auto open = std::priority_queue<Node*, std::vector<Node*>, NodeGreater>();
    auto closed = std::set<uint16_t*>();
    auto end = problem + (width * height - 1);

    open.push(new Node(problem, *problem + width + height - 2, nullptr));

    while(!open.empty()) {
        auto opened = open.top();
        open.pop();

        if(opened->node == end) {
            if (verbose) {
                print(problem, width, height, opened);
                std::cout << opened->cost << std::endl;
            }

            while(!open.empty()){
                delete open.top();
                open.pop();
            }

            closed.erase(closed.begin(), closed.end());

            return;
        }
        else {
            for(const auto& x: explore(problem, width, height, opened->node, closed)) {
                open.push(new Node(x, opened->cost + *x + (x < opened->node ? 1 : -1), opened));
            }

            closed.insert(opened->node);
        }
    }
}

int main() {
    srand(1208);
    auto printTheArray = true;

    auto problem = new uint16_t[M * N];

    for (auto i = 0; i < M; ++i)
        for (auto j = 0; j < N; ++j)
            problem[i * N + j] = rand() % range;

    if (printTheArray) {
        printArray(problem, N, M);
        std::cout << std::endl;
    }

    auto start = c_t;
    solve(problem, N, M);
    auto end = c_t;

    std::cout << "Solving took " << ms(end - start).count() << " ms." << std::endl;

    delete[] problem;

    return 0;
}
