#include "main.h"

void signs(char sign1,char sign2,char* oper,Dlist** headR,Dlist** headR1){
    if(sign1=='-' && sign2=='+'){
        if(oper[0]=='+' || oper[0]=='-'){
            (*headR)->data=(*headR)->data*-1;
        }
        else {
            (*headR1)->data=(*headR1)->data*-1;
        }
    }
    else if(sign1=='-' && sign2=='-' && oper[0]=='-'){
          (*headR)->data=(*headR)->data*-1;
    }
    else if(sign1=='-' && sign2=='-' && oper[0]=='+'){
          (*headR)->data=(*headR)->data*-1;
    }
     else if(sign1=='-' && sign2=='-' && oper[0]=='/'){
          (*headR1)->data=(*headR1)->data*1;
    }
    
    else if(sign1=='+' && sign2=='-' && oper[0]=='x'){
         (*headR1)->data=(*headR1)->data*-1;
    }
    else if(sign1=='+' && sign2=='-' && oper[0]=='/'){
        (*headR1)->data=(*headR1)->data*-1;
    }
    else if((sign1=='-' ||sign2=='-' )&& oper[0]=='/'){
        if((*headR1)->data!=0){
            (*headR1)->data=(*headR1)->data*-1;
        }
    }
}