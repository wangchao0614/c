#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <stdexcept>

using namespace std;

class Image {
private:
    int width, height;
    vector<vector<int>> pixels;

public:
    // 构造函数
    Image() : width(0), height(0) {}

    Image(int w, int h) : width(w), height(h) {
        pixels = vector<vector<int>>(height, vector<int>(width, 0));
    }

    // 判空
    void isEmpty() const {  
        for (int i = 0; i < height; ++i) {  
            for (int j = 0; j < width; ++j) {  
                if (pixels[i][j] != 0) {  
                    // 如果找到一个非零像素，则图像不为空  
                    cout<<"图像不为空";
                }  
            }  
        }  
        // 如果所有像素都为零，则图像为空  
        cout<<"图像为空";
    }  

    // 读取图像
  void loadImage(const string& filename) {
        ifstream file(filename);
        if (!file.is_open()) {
            throw std::runtime_error("无法打开文件");
        }
        string line;
        vector<int> row;
        int value;
        while (getline(file, line)) {
            row.clear(); 
            istringstream iss(line);
            while (iss >> value) {
                row.push_back(value);
            }
            if (pixels.empty()) {
                height = 1;
                width = row.size();
                pixels.resize(height, vector<int>(width, 0));
            }
            if (row.size() != width) {
                throw runtime_error("文件无法读取");
            }
            pixels.push_back(row);
            height++; 
        }

        file.close();
    }

    // 保存图像
    void saveImage(const string &filename) const {
        ofstream file(filename);
        if (!file.is_open()) throw runtime_error("文件名错误，无法保存图像");

        file << width << " " << height << "\n";
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                file << pixels[i][j] << " ";
            }
            file << endl;
        }
        
        file.close();
    }

    // 显示图像
    void display() const {
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                cout << setw(5) <<pixels[i][j] << " ";
            }
            cout << endl;
        }
    }

    // 二值化显示
    void displayBinary() const {
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                cout << setw(5) << (pixels[i][j] == 0 ? '.' : 'O');
            }
            cout << endl;
              }
    }

    // 绘制点
    void drawPoint(int x, int y, int value) {
        if (x >= 0 && x < width && y >= 0 && y < height) {
            pixels[y][x] = value;
        }
    }

    // 绘制框
    void drawRectangle(int x, int y, int w, int h, int value) {
        for (int i = 0; i < h; ++i) {
            if (y + i >= 0 && y + i < height) {
                if (x >= 0 && x < width) pixels[y + i][x] = value;
                if (x + w - 1 >= 0 && x + w - 1 < width) pixels[y + i][x + w - 1] = value;
            }
        }
        for (int i = 0; i < w; ++i) {
            if (x + i >= 0 && x + i < width) {
                if (y >= 0 && y < height) pixels[y][x + i] = value;
                if (y + h - 1 >= 0 && y + h - 1 < height) pixels[y + h - 1][x + i] = value;
            }
        }
    }

    // 阈值化
    void threshold(int thr) {
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                if (pixels[i][j] <= thr) {
                    pixels[i][j] = 0;
                }
            }
        }
    }

    // 左右翻转
    void flipHorizontal() {
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width / 2; ++j) {
                swap(pixels[i][j], pixels[i][width - j - 1]);
            }
        }
    }

    // 顺时针旋转90度
    void rotate90() {
        vector<vector<int>> rotated(width, vector<int>(height));
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                rotated[j][height - 1 - i] = pixels[i][j];
            }
        }
        swap(width, height);
        pixels = rotated;
    }
};

// 主函数
int main() {
    Image img;
    int choice;

    do {
       cout << "菜单:"<<endl;
        cout << "1.创建图象"<<endl;
        cout << "2.  读取图像"<<endl;
        cout << "3.  保存图像"<<endl;
        cout << "4.  显示"<<endl;
        cout << "5.  二值化显示"<<endl;
        cout << "6.  绘制点"<<endl;
        cout << "7.  绘制框"<<endl;
        cout << "8.  阈值化"<<endl;
        cout << "9.  翻转"<<endl;
        cout << "10. 旋转"<<endl;
        cout << "11. 判空"<<endl;
        cout << "0.  推出"<<endl;
        cout << "输入你的选择"<<endl;
        cin >> choice;

        switch (choice) {
            case 1: {
                int w, h;
                cout << "输入图像的宽和高: ";
                cin >> w >> h;
                img = Image(w, h);
                cout << "图像已创建"<<endl;
                break;
            }
            case 2: {
                string filename;
                cout << "输入文件名: ";
                cin >> filename;
                try {
                    img.loadImage(filename);
                    cout << "图像输入于：" << filename << ".\n";
                } catch (const exception &e) {
                    cout << e.what() << endl;
                }
                break;
            }
            case 3: {
                string filename;
                cout << "输入文件名: ";
                cin >> filename;
                try {
                    img.saveImage(filename);
                    cout << "图像保存到：" << filename << ".\n";
                } catch (const exception &e) {
                    cout << e.what() << endl;
                }
                break;
            }
            case 4: {
                cout << "图像为:"<<endl;
                img.display();
                break;
            }
            case 5: {
                cout << "二值化图像显示为："<<endl;
                img.displayBinary();
                break;
            }
            case 6: {
                int x, y, value;
                cout << "输入 X, Y 和 值: ";
                cin >> x >> y >> value;
                img.drawPoint(x, y, value);
                cout << "绘制点"<<endl;
                break;
            }
            case 7: {
                int x, y, w, h, value;
                cout << "输入 X, Y, 宽, 高 和 值: ";
                cin >> x >> y >> w >> h >> value;
                img.drawRectangle(x, y, w, h, value);
                cout << "绘制框"<<endl;
                break;
            }
            case 8: {
                int thr;
                cout << "输入阈值: ";
                cin >> thr;
                img.threshold(thr);
                cout << "阈值化为"<<endl;
                break;
            }
            case 9: {
                img.flipHorizontal();
                cout << "图像翻转"<<endl;
                break;
            }
            case 10: {
                img.rotate90();
                cout << "图像旋转"<<endl;
                break;
            }
            case 11:{
            	img.isEmpty();
				break;
			}
            case 0:
                cout << "退出..."<<endl;
                break;
            default:
                cout << "选择错误，请重新选择"<<endl;
                break;
        }
    } while (choice != 0);

    return 0;
}