#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <ctime>
#include <cmath>
#include <random>
#include "sha256.cpp"

using namespace std;

class user {
	protected:
		string  gen_random(int len) {
			string s;
			static const char alphanum[] =
				"0123456789"
				"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
				"abcdefghijklmnopqrstuvwxyz"
				"!@#$%^&*()_+=/|<>?:{},.;'\[]";
			for (int i = 0; i < len; ++i) {
				s += alphanum[rand() % (sizeof(alphanum) - 1)];
			}
			return sha256(s);
		}
		string  gen_randomForName(int len) {
			string s;
			static const char alphanum[] =
				"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
				"abcdefghijklmnopqrstuvwxyz";
			for (int i = 0; i < len; ++i) {
				s += alphanum[rand() % (sizeof(alphanum) - 1)];
			}
			return s;
		}
		string generatePublicKey() {
			string publicKey;
			publicKey = gen_random(1000);
			return publicKey;
		}
		string generatePrivateKey() {
			string privateKey;
			privateKey = gen_random(1000);
			return privateKey;
		}
		string generateName() {
			string name;
			name = gen_randomForName(8);
			return name;
		}
		void setPrivateKey(string input) { this->privateKey = input; }
		void setPublicKey(string input) { this->publicKey = input; }
		void setName(string input) { this->name = input; }
		void createBalance(int input) { this->balance = fabs(rand()); }
	private:
		string publicKey = "";
		string name = "";
		string privateKey="";
		string getPrivateKey() { return privateKey; }
		int balance = 0;
	public:
		user() {
			setPrivateKey(generatePrivateKey());
			setPublicKey(generatePublicKey());
			setName(generateName());
			createBalance(balance);
		}
		int setBalance(int amountTraded) {
            this->balance = this->balance - amountTraded;
            return this->balance;
		}
		int rewardMiner(int difficultyTarget){
		    int amountRewarded = 3 * difficultyTarget;
            this->balance = this->balance + amountRewarded;
            return this->balance;
		}
		int getBalance(){
		    return balance;
        }
		string getPublicKey() {
			return publicKey;
		};
		string getName() {
			return name;
		}
};

class transaction{
 private:
     string timestamp;
     user user1;
     user user2;
     int amountTraded;
     string transactionHash;
 public:
     user setUser1(user user){
        this->user1 = user;
        return this->user1;
     }
     user setUser2 (user user){
        this->user2 = user;
        return this->user2;
     }
     int setAmountTraded(int amount){
        this->amountTraded = amount;
        return this->amountTraded;
     }
     string getUser1PubKey() {
         return this->user1.getPublicKey();
     }
     string getUser2PubKey() {
         return this->user2.getPublicKey();
     }
     string getTimestamp() {
         return this->timestamp;
     }
     int getAmountTraded() {
         return this->amountTraded;
     }
     string getTransactionHash(){
        return this->transactionHash;
     }

    void performTransaction(int amountTraded){
        user1.setBalance(this->amountTraded);
        user2.setBalance(-(this->amountTraded));
        time_t now = time(0);
        this->timestamp = ctime(&now);
        this->transactionHash = sha256(to_string(amountTraded) + getUser1PubKey() + getUser2PubKey() + getTimestamp());
    }
};
