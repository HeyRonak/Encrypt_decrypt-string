#include<iostream>
#include<unistd.h>
using namespace std;

void Animation(){
    cout << "\nIn Process,please wait : \n";
    for(int i=0;i<5;++i){
        sleep(1);
        cout << "*";
    }
}

class Algorithm{

    public:
       virtual void Encrypt() = 0;
       virtual void Decrypt() = 0;

};

class EncryptString : public Algorithm{

    string text;

    public:
        void Encrypt(){
            cout << "\nEnter your text that u want to encrypt:\n";
            cin >> text;
            string orinal = text;
            int size = text.size();
            for(int i=0;i<size/2;i++){
                text[i]++;
                text[size-1-i]++;
                char stemp = text[i];
                text[i] = text[size-1-i];
                text[size-1-i] = stemp;
            }

            Animation();
            system("cls");
            cout << "\nYOUR ORIGINAL TEXT IS : " << orinal << "\n";
            cout << "YOUR ENCRYPTED TEXT IS : " << text << "\n";
        }


        void Decrypt(){
            cout << "\nEnter your text that u want to decrypt:\n";
            cin.ignore();
            cin >> text;
            string orinal = text;
            int size = text.size();
            for(int i=0; i<size/2; i++){
                text[i]--;
                text[size-1-i]--;
                char stemp = text[i];
                text[i] = text[size-1-i];
                text[size-1-i] = stemp;
	        }

            Animation();
            system("cls");
            cout << "\nYOUR ORIGINAL TEXT IS : " << orinal << "\n";
            cout << "YOUR DECRYPTED TEXT IS : " << text << "\n";

        }

};

int main()
{   

    EncryptString es1;
    char ch;
    do{

        cout << "\n\t1.Encryption:\n";
        cout << "\t2.Decryption:\n";
        cout << "\t3.Exit:\n";
        cout << "\nEnter your choice:\n";
        cin >> ch;
        switch(ch){
            
            case '1':
                es1.Encrypt();
                break;
            case '2':
                es1.Decrypt();
                break;
            case '3':
                exit(0);
        }

    }while(ch != '3');

    
    return 0;
}
