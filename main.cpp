#include <iostream>
std::string simbol_first = "1234567890QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm!#$%&*+-'./=?^_`{|}~\\";
std::string simbol_second = "1234567890QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm.-";
bool valid=true;

std::string first (std::string first_part)
{
    int index = first_part.find('@');
    first_part = first_part.substr(0, index);
    return first_part;
}
std::string second (std::string second_part)
{
    int index = second_part.rfind('@');
    second_part = second_part.substr(index+1, second_part.length());
    return second_part;
}

bool simbol (std::string text, std::string dictionary) {
   bool result = true;
    for (int i = 0; i < text.length();i++) {
       if (dictionary.find(text[i]) == -1)  {
          result = false;
          break ;
       }

    }
    return result;
}

int main() {
    std::string email, first_part, second_part;
    std::cout << "Email Verify!" << std::endl;
    std::cout << "Input email: "<< std::endl;
    std::cin >> email;
    first_part = first (email);
    second_part =  second (email);
    if (first_part.length() + second_part.length() + 1 == email.length()  && (first_part.length() >= 1 && first_part.length() <= 64) &&
       (second_part.length() >= 1 && second_part.length() <= 63)) {

        if  (first_part.find("..") != -1)  valid = false;
        if (!simbol (first_part,simbol_first))  valid = false;
        if (!simbol (second_part,simbol_second)) valid = false;
        if (first_part[0] == '.' ) valid = false;
        if (second_part[second_part.length()-1] == '.') valid = false;
    }
    else {
        valid = false;
    }
    if (!valid) {
        std::cout << "NO!" << "\n";}
    else {
        std::cout << "YES!"<< "\n";
    }

}
