#include <iostream>
#include <vector>
using namespace std;
class mat{
    public:
        virtual void product(){}
};
class pMat : public mat {
    public:
        vector<vector<int> > arr;
        int m, n;
        void read(){
            cout << "Enter the dimensions of the matrix: ";
            cin >> m >> n;
            arr.resize(m, vector<int>(n));
            for(int i = 0; i < m; i++)
                for(int j = 0; j < n; j++)
                    cin >> arr[i][j];
        }
        void display(){
            for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++)
                    cout << arr[i][j] << " ";
                cout << endl;
            }
        }
        void product(){
            pMat mat1, mat2;
            mat1.read();
            mat2.read();
            int m1, n1, m2, n2;
            m1 = mat1.m;
            n1 = mat1.n;
            m2 = mat2.m;
            n2 = mat2.n;
            vector<vector<int> > finMat(m1, vector<int>(n2));
            for(int i = 0; i < m1; i++)
                for(int j = 0; j < n2; j++)
                    for(int i1 = 0; i1 < n1; i1++)
                        finMat[i][j] += mat1.arr[i][i1] * mat2.arr[i1][j];
            cout << endl;
            for(int i = 0; i < m1; i++){
                for(int j = 0; j < n2; j++)
                    cout << finMat[i][j] << " ";
                cout << endl;
            }
        }
};
int main(){
    mat *ptr;
    pMat obj;
    ptr = &obj;
    ptr->product();
    return 0;
}