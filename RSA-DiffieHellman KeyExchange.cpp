#include<iostream>
#include<math.h>

using namespace std;

int gcd(int x, int y){
    int temp;
    while(1){
        temp = x % y;
        if(temp == 0){
            return y;
        }
        x = y;
        y = temp;
    }
}

void rsa(){
    double p, q, n;
    cout<<"Enter two large prime numbers "<<endl;
    cin>>p>>q;
    n = p * q;
    double check, phi;
    phi = (p-1)*(q-1);
    double e = 7;
    while(e<phi){
        check = gcd(e,phi);
        if(check==1)
            break;
        else
        e++;
    }
    double d;
    d=1/e;
    d=fmod(d,phi);
    double message;
    cout<<"Enter Plaintext: ";
    cin>>message;
    double c,m;
    c = pow(message,e);
    m = pow(c,d);
    c=fmod(c,n);
    m=fmod(m,n);
    cout<<"n = pq = "<<n<<endl;
    cout<<"phi = "<<phi<<endl;
    cout<<"e = "<<e<<endl;
    cout<<"After encryption..."<<endl; 
    cout<<"Ciphertext: "<<c<<endl;
    cout<<"After decryption... "<<endl;
    cout<<"Plaintext: "<<m;
}

int hellman(int a, int k1, int k2){
    int x, y;
    y = 1;

	while (k1 > 0){
        x = k1 % 2;
		if (x == 1){
		    y = (y*a) % k2;
		}
		a = a*a % k2;
		k1 = k1 / 2;
	}
	return y;
}

void diffieHellman(){
    int q, a, privateKey1, privateKey2, publicKey1, publicKey2;	
    cout<<"Enter q and a"<<endl;
    cin>>q>>a;
    cout<<"Enter private key for Alice: "; 
    cin>>privateKey1;
    cout<<"Enter private key for Bob: "; 
    cin>>privateKey2;

	publicKey1 = hellman(a, privateKey1, q);
    publicKey2 = hellman(a, privateKey2, q);

	int secretKey1 = hellman(publicKey2, privateKey1, q);
	int secretKey2 = hellman(publicKey1, privateKey2, q);
    cout<<"\nAlice's Public Key "<<publicKey1<<endl;
    cout<<"Bob's Public Key "<<publicKey2<<endl;
    cout<<"\nAlice's Secret Key "<<secretKey1<<endl;
    cout<<"Bob's Secret Key "<<secretKey2<<endl;
    cout<<"Secret Keys are generated!!"<<endl;
}


int main(){
    int choice;

    cout<<"Enter 1 for RSA Algorithm \n";
	cout<<"Enter 2 for Diffie-Hellman Key Exchange Algorithm\n";
    cin>>choice;
    switch(choice){
        case 1:rsa();
                break;
        case 2:diffieHellman();
                break;
        default:cout<<"You did not enter 1 or 2!\n";
    }
    return 0;
}