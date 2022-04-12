#include <iostream>
#include <vector>
#include <numeric>
#include <string>
#include <sstream>
#include "Matrix.hpp"
using namespace std;


namespace zich{
        Matrix Matrix::operator-() const{            
            Matrix mat2{this->_mat, this->_rows, this->_cols};
            for (unsigned long i = 0; i < mat2._mat.size(); i++)
            {
                mat2._mat[i] = -this->_mat[i];
            }
            return mat2;
        }
        Matrix Matrix::operator-(const Matrix& other) const{
            if(this->_cols != other._cols || this->_rows != other._rows){
                throw invalid_argument("invalid action");
            }
            Matrix mat2{this->_mat, this->_rows, this->_cols};
            for (unsigned long i = 0; i < mat2._mat.size(); i++)
            {
                mat2._mat[i] -= other._mat[i];
            }
            return mat2;
        }

        void Matrix::operator-=(const Matrix& other) {
            if(this->_cols != other._cols || this->_rows != other._rows){
                throw invalid_argument("invalid action");
            }
            for (unsigned long i = 0; i < this->_mat.size(); i++)
            {
                this->_mat[i] -= other._mat[i];
            }
        }

        Matrix Matrix::operator+() const {
            Matrix mat2{this->_mat, this->_rows, this->_cols};
            return mat2;
        }

        Matrix Matrix::operator+(const Matrix& other){
            if(this->_cols != other._cols || this->_rows != other._rows){
                throw invalid_argument("invalid action");
            }
            Matrix mat2{this->_mat, this->_rows, this->_cols};
            for (unsigned long i = 0; i < mat2._mat.size(); i++)
            {
                mat2._mat[i] += other._mat[i];
            }
            return mat2;
        }

        void Matrix::operator+=(const Matrix& other) {
            if(this->_cols != other._cols || this->_rows != other._rows){
                throw invalid_argument("invalid action");
            }
            for (unsigned long i = 0; i < this->_mat.size(); i++)
            {
                this->_mat[i] += other._mat[i];
            }
        }

        bool Matrix::operator<(const Matrix& other) const{
            if(this->_cols != other._cols || this->_rows != other._rows){
                throw invalid_argument("invalid action");
            }
            double sum1= 0;
            double sum2= 0;
            for (unsigned long i = 0; i < this->_mat.size(); i++)
            {
                sum1 += this->_mat[i];
            }
            for (unsigned long i = 0; i < other._mat.size(); i++)
            {
                sum2 += other._mat[i];
            }
            
            return sum1 < sum2;
        }

        bool Matrix::operator<=(const Matrix& other) const{
            if(this->_cols != other._cols || this->_rows != other._rows){
                throw invalid_argument("invalid action");
            }
            double sum1= 0;
            double sum2= 0;
            for (unsigned long i = 0; i < this->_mat.size(); i++)
            {
                sum1 += this->_mat[i];
            }
            for (unsigned long i = 0; i < other._mat.size(); i++)
            {
                sum2 += other._mat[i];
            }
            return sum1 <= sum2;
        }

        bool Matrix::operator>(const Matrix& other) const{
            if(this->_cols != other._cols || this->_rows != other._rows){
                throw invalid_argument("invalid action");
            }
            double sum1= 0;
            double sum2= 0;
            for (unsigned long i = 0; i < this->_mat.size(); i++)
            {
                sum1 += this->_mat[i];
            }
            for (unsigned long i = 0; i < other._mat.size(); i++)
            {
                sum2 += other._mat[i];
            }
            return sum1 > sum2;
        }

        bool Matrix::operator>=(const Matrix& other) const{
            if(this->_cols != other._cols || this->_rows != other._rows){
                throw invalid_argument("invalid action");
            }
            double sum1= 0;
            double sum2= 0;
            for (unsigned long i = 0; i < this->_mat.size(); i++)
            {
                sum1 += this->_mat[i];
            }
            for (unsigned long i = 0; i < other._mat.size(); i++)
            {
                sum2 += other._mat[i];
            }
            return sum1 >= sum2;
        }

        bool Matrix::operator==(const Matrix& other) const{
            if(this->_cols != other._cols || this->_rows != other._rows){
                throw invalid_argument("invalid action");
            }
            for (unsigned long i = 0; i < _rows*_cols; i++)
            {
                if(this->_mat[i] != other._mat[i]){
                    return false;
                }
            }
            return true;
        }

        bool Matrix::operator!=(const Matrix& other) const{
            if(this->_cols != other._cols || this->_rows != other._rows){
                throw invalid_argument("invalid action");
            }
            return !(*this == other);
        }

        Matrix Matrix::operator++(){
            for (unsigned long i = 0; i < this->_mat.size(); i++)
            {
                this->_mat[i] += 1;
            }
            return *this;
        }

        Matrix Matrix::operator++(int dummy_flag_for_postfix_increment) {
            Matrix copy = *this;
            for (unsigned long i = 0; i < this->_mat.size(); i++)
            {
                this->_mat[i] += 1;
            }
            return copy;         
        }

        Matrix Matrix::operator--() {
            for (unsigned long i = 0; i < this->_mat.size(); i++)
            {
                this->_mat[i] -= 1;
            }
            return *this;
                    
        }

        // postfix increment:
        Matrix Matrix::operator--(int dummy_flag_for_postfix_increment) {
            Matrix copy = *this;
            for (unsigned long i = 0; i <this->_mat.size(); i++)
            {
                this->_mat[i] -= 1;
            }
            return copy;
        }

        void Matrix::operator*=(const double num){
            for (unsigned long i = 0; i < this->_mat.size(); i++)
            {
                this->_mat[i] *= num;
            }
        }

        void Matrix::operator*=(const Matrix& other){
            if(this->_cols != other._rows){
                throw invalid_argument("invalid action");
            }
            for (unsigned long i = 0; i < this->_rows; i++)
            {
                for (unsigned long j = 0; j < other._cols; j++)
                {
                    double sum = 0;
                    for (unsigned long k = 0; k < other._rows; k++)
                    {
                        sum += (this->_mat[i*(unsigned long)this->_cols + k] * other._mat[k*(unsigned long)other._cols + j]);
                    }
                    this->_mat[i*(unsigned long)other._cols + j] = sum;
                }
            }
        }

        Matrix Matrix::operator*(const Matrix& other){
            if(this->_cols != other._rows){
                throw invalid_argument("invalid action");
            }
            vector<double> multMat;
            for (unsigned long i = 0; i < this->_rows; i++)
            {
                for (unsigned long j = 0; j < (unsigned long)other._cols; j++)
                {
                    double sum = 0;
                    for (unsigned long k = 0; k < other._rows; k++)
                    {
                        sum += this->_mat[i*(unsigned long)this->_cols + k] * other._mat[k * (unsigned long)other._cols + j];
                    }
                    multMat.push_back(sum);
                }
            }
            Matrix mult(multMat, this->_rows, other._cols);
            return mult;
        }

        Matrix operator*(const double num, const Matrix& other){
            Matrix mat2{other._mat, other._rows, other._cols};
            for (unsigned long i = 0; i < mat2._mat.size(); i++)
            {
                mat2._mat[i] *= num;
            }
            return mat2;
        }

        Matrix Matrix::operator*(const double num){
            Matrix mat2{this->_mat, this->_rows, this->_cols};
            for (unsigned long i = 0; i < this->_mat.size(); i++)
            {
                mat2._mat[i] *= num;
            }
            return mat2;
        }


        std::ostream& operator<< (std::ostream& output, const Matrix& mat){
            for (unsigned long i = 0; i < (unsigned long)(mat._rows); i++)
            {
                output << "[";
                for (unsigned long j = 0; j < mat._cols-1; j++)
                {
                    output << mat._mat[i*(unsigned long)mat._cols + j] << " ";
                }
                output << mat._mat[i*(unsigned long)mat._cols + (unsigned long)mat._cols-1] << "]";
                if(i != (unsigned long)(mat._rows)-1){
                    output << "\n";
                }
            }
            return output;
        }

        std::istream& operator>> (std::istream& input , Matrix& mat){  
            mat._mat.clear();
            string matInput;
            string matRows;
            int rows = 0;
            int cols = 0;
            getline(input, matInput);
            stringstream lines(matInput);
            while(getline(lines, matRows, ',')){
                if(matRows.empty() || (rows > 0 && matRows[0] != ' ')){
                    throw invalid_argument("invalid input of matrix");
                }
                rows++;
                stringstream str;
                if(rows == 1){
                    str << matRows;
                }
                else{
                    str << matRows.substr(1);
                }
                string snippet;
                getline(str, snippet, ' ');
                if (snippet[0] != '['){
                        throw invalid_argument("invalid input of matrix");
                    }
                try{
                    mat._mat.push_back(stod(snippet.substr(1)));
                }
                catch(const std:: exception& e){
                    throw invalid_argument("invalid input");
                }
                int col = 1;
                while(getline(str, snippet, ' ')){
                    col++;
                    if(snippet.back() != ']'){
                       try{
                            mat._mat.push_back(stod(snippet));
                        }
                        catch(const std:: exception& e){
                            throw invalid_argument("invalid input");
                        } 
                    }
                    else{
                        try{
                            mat._mat.push_back(stod(snippet.substr(0, snippet.size()-1)));
                        }
                        catch(const std:: exception& e){
                            throw invalid_argument("invalid input");
                        } 
                    }
                    if(rows == 1){
                        cols = col;
                    }
                } 
            if(rows > 0 && cols > 0){
                mat._rows = rows;
                mat._cols = cols;
            }   
        }  
        return input; 
    }
}
