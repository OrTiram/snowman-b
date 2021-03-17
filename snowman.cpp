#include <string>
#include <iostream>
#include "snowman.hpp"
#include <array>
#include <stdexcept>

using namespace std;

namespace ariel{

string snowman(int input){
    int inputTemp = input;
    const int count = 8;
    int inputTemp1 = 0 ;
    const int Division = 10;
    string ans ;

    if (input <= 0){ throw out_of_range{"Invalid input"};}

    for (int i = 0; i < count; i++)
    {  
    inputTemp1 = inputTemp % Division;
        if(inputTemp1 < 1 || inputTemp1 > 4){
         throw out_of_range{"Invalid code"}; 
      }
      inputTemp = inputTemp/Division;
    }
        if(inputTemp > 0){
         throw out_of_range{"Invalid input"}; 

        }


    const int length = 4;
    std::array<std::string,length> Hat = { "_===_", "___\n.....","  _\n /_\\", "___\n(_*_)" };
    std::array<std::string,length> L_Arm = {"<", "\\","/",""};
    std::array<std::string,length> R_Arm = {">", "/","\\",""};
    std::array<std::string,length> L_Eye = {".", "o", "O", "-"};
    std::array<std::string,length> R_Eye = {".", "o", "O", "-"};
    std::array<std::string,length> Nose = {",",".","_"," "};
    std::array<std::string,length> Torso = {"( : )","(] [)","(> <)","(   )"};
    std::array<std::string,length> Base = {"( : )","(\" \")","(___)","(   )"};

    int L_Arm_up = 0;
    int R_Arm_up = 0;
    int temp = input;
    
    string base = Base.at(temp%Division-1);
    temp = temp /Division;


    string torso = Torso.at(temp%Division-1);
    temp = temp /Division;

    if(temp%Division == 2){
       R_Arm_up = 2;
        }

    string right_Arm = R_Arm.at(temp%Division-1);
    temp = temp /Division;

    if(temp%Division == 2){
       L_Arm_up = 2;
        }

    string left_Arm = L_Arm.at(temp%Division-1);
    temp = temp /Division;

    string right_Eye = R_Eye.at(temp%Division-1);
    temp = temp /Division;
            
    string left_Eye = L_Eye.at(temp%Division-1);
    temp = temp /Division;

        
    string nose = Nose.at(temp%Division-1);
    temp = temp /Division;


    string hat = Hat.at(temp%Division-1);

    string Face = "("+left_Eye+nose+right_Eye+")";

   
    if(L_Arm_up == 2){
    ans =" "+ hat+"\n"+left_Arm + Face;
    if(R_Arm_up == 2){
        ans = ans + right_Arm +"\n"+torso+"\n"+base;
    }
    else  {
        ans = ans+"\n"+" "+torso+right_Arm+"\n"+" "+base;
            
    }
    }
    else if(R_Arm_up == 2){
           ans = hat+"\n"+Face+right_Arm+"\n"+left_Arm+torso+"\n"+base;
           
    }
    else {
        ans = hat+"\n"+Face+"\n"+left_Arm+torso+right_Arm+"\n"+base;
    }
       
    return ans;
}
};

