#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
struct CompArea;

class Rect { 
    int w, h;
public:
    Rect() : w(0), h(0) {}
    Rect(int w, int h) : w(w), h(h) {  }
    int area() { return w * h; }
    void print() {
        std::cout << "(" << w << "," << h << ")" << std::endl;
    }
};

bool compare (Rect& a, Rect& b) {
    int a_area = a.area();
    int b_area = b.area();
    return a_area < b_area;
}


int main() {
    int count;
    int width[10];
    int height[10];
    std::vector<Rect> vectorOfRect;

    std::cout << "사각형의 갯수: ";
    std::cin >> count;

    for (int i = 0; i < count; i++) {
        std::cout << "사각형의 폭: ";
        std::cin >> width[i];
        std::cout << "사각형의 높이: ";
        std::cin >> height[i];
    }


    for (int i = 0; i < count; i++) {
        Rect temp(width[i], height[i]);
        vectorOfRect.push_back(temp);
    }
    
    sort(vectorOfRect.begin(), vectorOfRect.end(), compare);

    std::vector<Rect>::iterator it;
    for (it = vectorOfRect.begin(); it != vectorOfRect.end(); ++it) {
        Rect temp = *it;
        temp.print();
    }
    
    return 0;

}
