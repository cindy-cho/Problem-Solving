// @ts-ignore
string upperToLower(string input){
    for(int i=0;i<input.length();i++){
        if(input[i]>='A' and input[i]<='Z'){
            input[i] = input[i] - ('A'-'a');
        }
    }
    return input;
}
