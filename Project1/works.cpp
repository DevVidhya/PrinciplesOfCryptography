#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll N = 1e6;
const ll cnt = 10;
const ll vSize = 500;

vector<ll>primes,v,store,v2,smoothNumber;
ll isPrime[N];



ll modEx(ll a,ll n,ll mod){
    a%=mod;
    ll res = 1;

    while(n){
        if(n%2){
            res*=a;
            res%=mod;
        }
        a*=a;
        a%=mod;
        n>>=1;
    }

    return res;
}

void SieveE(){

    for(int i=0;i<N;i++) isPrime[i] = 1;

    for(int i=2;i<N;i++){
        if(isPrime[i]){
            primes.push_back(i);

            for(int j=2;i*j<N;j++){
                isPrime[i*j]=0;
            }
        }
    }
}

void fillV(ll n){
    ll sqn = ceil(sqrt(n));
    for(int i=0;i<vSize;i++){
        v.push_back((i+sqn)*(i+sqn)-n);
    }
    v2 = v;
}

ll findSqrt(ll a,ll p){

    while(1){
        // cout<<a<<" "<<p<<"\n";
        ld sq = sqrt(a);
        if(ceil(sq)==floor(sq)){
            return ((ll)sq)%p;
        }
        a+=p;
    }
}

void Sieve(ll n){

    for(auto p: store){
        if(p==2){
            for(int i=0;1+i*p<vSize;i++){
                v2[1+i*p]/=p;
            }

            continue;
        }
        ll a = n%p;
        ll sq1 = findSqrt(a,p);
        ll sq2 = -sq1 + p;

        ll sol1 = sq1-ceil(sqrt(n));
        ll sol2 = sq2-ceil(sqrt(n));

        while(sol1<0) sol1+=p;
        while(sol2<0) sol2+=p;
        // cout<<sol1<<" "<<sol2<<"\n";



        // cout<<p<<" "<<sol1<<" "<<sol2<<"\n";
        
        for(int i=0;sol1+i*p<vSize;i++){
            v2[sol1+i*p]/=p;
        }

        for(int i=0;sol2+i*p<vSize;i++){
            v2[sol2+i*p]/=p;
        }
    }
}


int gauss (vector < bitset<cnt+1> > a, int n, int m, bitset<3> & ans) {
    vector<int> where (m, -1);
    for (int col=0, row=0; col<m && row<n; ++col) {
        for (int i=row; i<n; ++i)
            if (a[i][col]) {
                swap (a[i], a[row]);
                break;
            }
        if (! a[row][col])
            continue;
        where[col] = row;

        for (int i=0; i<n; ++i)
            if (i != row && a[i][col])
                a[i] ^= a[row];
        ++row;
    }
        // The rest of implementation is the same as above
}


int main(){

    SieveE();

    ll n;
    cin>>n;

    ll cntr = 0,i=1;

    // cout<<findSqrt(15347,17)%17<<"\n";

    // return 0;

    if(n%2){
        store.push_back(2);
        cntr++;
    }

	//to store the primes having qr

    while(cntr<cnt && i<N){
        
        if(modEx(n,(primes[i]-1)>>1,primes[i])==1){
            store.push_back(primes[i]);
            cntr++;
        }
        i++;
    }

    // for(auto x: store){
    //     cout<<x<<" ";
    // }

    // return 0;

    fillV(n);

    // for(auto x: v){
    //     cout<<x<<" ";
    // }

    // return 0;

    Sieve(n);

    // cout<<v.size()<<"\n";

    for(int i=0;i<vSize;i++){
        // cout<<v[i]<<" "<<v2[i]<<"\n";
        if(v2[i]==1){
            smoothNumber.push_back(v[i]);
        }
    }

    // for(auto x: smoothNumber){
    //     cout<<x<<" ";
    // }
    // return 0;

    // const int sz = store.size();

    /*vector< vector<int> >mat(smoothNumber.size(),vector<int>(store.size()));

    for(int i=0;i<smoothNumber.size();i++){
        ll temp2 = smoothNumber[i];
        for(int j=0;j<store.size();j++){
            ll ptr = 0;

            while(temp2%store[j]==0){
                ptr++;
                temp2/=store[j];
            }
            mat[i][j] = ptr%2;

        }

    }*/

    vector<vector<ll>>subsets;

    for(ll mask = 1; mask<(1LL<<smoothNumber.size()); mask++){
        vector<ll>ans(store.size(),0);
        vector<ll>tmp;
        for(int j=0;j<smoothNumber.size();j++){
            if(mask&(1LL<<j)){
                for(int k=0;k<store.size();k++){
                    ans[k]+=mat[j][k];
                }
                tmp.push_back(smoothNumber[j]);
            }
        }

        bool done =true;

        for(int i=0;i<store.size();i++){
            if(ans[i]%2){
                done = false;
                break;
            }
        }

        if(done){
            subsets.push_back(tmp);
        }
    }

    //cout<<subsets.size()<<"\n";

    set<ll>factor;

    for(auto st: subsets){

        ll x = 1,y=1;
        for(auto ele: st){
            // cout<<y<<" ";
            // cout<<ele<<" "<<findSqrt(ele,n)<<"\n";
            ll sq2 = findSqrt(ele,n);
            x*=ele;
            y*=sq2;
        }

        x = sqrt(x);

        ll ans1 = __gcd(abs(x-y),n);
        ll ans2 = __gcd(x+y,n);

        if(ans1!=1 && ans1!=-1 && ans1!=n){
            // cout<<ans1<<"\n";
            factor.insert(ans1);
        }


        if(ans2!=1 && ans2!=-1 && ans2!=n){
            // cout<<ans2<<"\n";
            factor.insert(ans2);
        }

        // cout<<__gcd(abs(x-y),n)<<" "<<__gcd(x+y,n)<<"\n";
    }

    cout<<"Some of the non trivial factors are:\n";

    for(auto x: factor){
        cout<<x<<"\n";
    }

    // for(auto x: smoothNumber){
    //     // cout<<x<<"\n";
    //     vector<ll>temp;
    //     ll temp2 = x;
        

    //     // cout<<x<<": ";

    //     for(auto y: store){
    //         ll ptr=0;
    //         while(temp2%y==0){
    //             ptr++;
    //             temp2/=y;
    //         }

    //         // cout<<y<<" "<<ptr<<", ";

    //         temp.push_back(ptr%2);
    //     }
    //     // cout<<"\n";

    //     mat.push_back(temp);
    // }

    // for(auto x: mat){
    //     for(auto y: x){
    //         cout<<y<<" ";
    //     }

    //     cout<<"\n";
    // }

}
