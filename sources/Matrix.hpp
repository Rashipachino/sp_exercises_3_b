#include <iostream>
#include <vector>
using namespace std;

namespace zich{
    class Matrix{
        private:
            int _rows;
            int _cols;
            vector<double> _mat;
        public:
            //constructor
            Matrix(vector<double> vect, int rows, int cols)
                : _rows(rows), _cols(cols), _mat(vect){
                    if(rows < 1 || cols < 1 || vect.size() != rows*cols){
                        __throw_invalid_argument("invalid argument");
                    }
                }
                
            Matrix(const Matrix& other)
                : _rows(other._rows), _cols(other._cols), _mat(other._mat){
                }
                
        
            Matrix operator-() const;
            Matrix operator-(const Matrix& other) const;
            void operator-=(const Matrix& other);
            Matrix operator+() const;
            Matrix operator+(const Matrix& other);
            void operator+=(const Matrix& other);
            bool operator<(const Matrix& other) const;
            bool operator<=(const Matrix& other) const;
            bool operator>(const Matrix& other) const;
            bool operator>=(const Matrix& other) const;
            bool operator==(const Matrix& other) const;
            bool operator!=(const Matrix& other) const;
            Matrix operator++();
            Matrix operator++(int dummy_flag_for_postfix_increment);
            Matrix operator--();
            Matrix operator--(int dummy_flag_for_postfix_increment);
            void operator*=(const double num);
            void operator*=(const Matrix& other);
            friend Matrix operator*(const double num, const Matrix& other);
            Matrix operator*(const Matrix& other);
            Matrix operator*(const double num);
            friend ostream& operator<< (std::ostream& output, const Matrix& mat);
            friend istream& operator>> (std::istream& input , Matrix& mat);
    };
}
