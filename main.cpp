#include <iostream>
std::string normal = "QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm!#$%&*+-'\/=?^_`{|}~";
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

bool simbol (std::string text) {
   bool result = true;
    for (int i = 0; i < text.length();i++) {
       // for (int j = 0; j < normal.length(); j++) {
            if (normal.find(text[i]) == -1)  {
               result = false;
               break ;
            }
       // }
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
    if (first_part.length()+second_part.length()+1 == email.length()  && (first_part.length()>=1 && first_part.length()<=64) &&
       (second_part.length()>=1 && second_part.length()<=63)) {

        if  (first_part.find("..") != -1)  valid = false;
      std::cout << first_part.find("..") << "\n";
        valid = simbol (first_part) ;
    }
    else {
        valid = false;
        std::cout << "Error!!!!" << "\n";
    }


    if (!valid) {
        std::cout << "ERROR" << "\n";}
    else {
        std::cout << "VALID"<< "\n";
    }
    std::cout << first (email) << "\n";
    std::cout << second (email) << "\n";
    std::cout << valid << "\n";

    return 0;
}
