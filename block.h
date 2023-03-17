#pragma once
#include "User.h"
#include <fstream>

using namespace std;

class block {
	private:
    string prevBlockHash = "this is the genesis block";
    string merkelTreeHash;
	string blockHash;
	string timeStamp;
	int index;
	int nonce;
	int version;
	int difficultyTarget;
	double durationTakenToMine;
	protected:
	int createNonce(int difficultyTarget){
	    this->nonce = fabs(rand()) / pow(2, difficultyTarget);
        return this->nonce;
	}
	public:
	block() {
		blockHash = sha256((to_string(nonce)) + this->prevBlockHash + (to_string(this->difficultyTarget)) + (to_string(this->version)) + this->timeStamp);
		merkelTreeHash = sha256(blockHash + prevBlockHash);
		time_t now = time(0);
		timeStamp = ctime(&now);
		version = 1;
		index = 0;
		difficultyTarget = 1;
		nonce = createNonce(difficultyTarget);
	}
	string setTimestamp(){
        time_t now = time(0);
        this->timeStamp = ctime(&now);
        return this->timeStamp;
	}
    string takePrevBlockHash(block block){
        this->prevBlockHash = block.getBlockHash();
        return this->prevBlockHash;
    }
    string getMerkelTreeHash(){
        return this->merkelTreeHash;
    }
    string calculateMerkellTreeHash(block prevblock){
       this->merkelTreeHash = sha256(getBlockHash() + getBlockHash() + getBlockHash() + getPrevBlockHash());
       return this->merkelTreeHash;
    }

    string getPrevBlockHash(){
        return this->prevBlockHash;
    }
	string getBlockHash() {
		return this->blockHash;
	}
	string getTimeStamp() {
		return this->timeStamp;
	}
	int getNonce(){
        return this->nonce;
	}
	int getVersion() {
		return this->version;
	}
	double getDuration(){
        return this->durationTakenToMine;
	}
	double setDuration(auto duration){
        durationTakenToMine = duration;
        return this->durationTakenToMine;
	}
	int getIndex(){
        return this->index;
	}
	int setIndex(int input){
	    this->index = input;
	    return this->index;
	}
	int getDifficultyTarget(){
        return this->difficultyTarget;
	}

    int calculateDifficultyTarget(int index){
        if(index == pow(2, this->difficultyTarget)){
            this->difficultyTarget=this->difficultyTarget+1;
        }
        return this->difficultyTarget;
    }

	vector<transaction> transactionList;

    vector<transaction> addTransactionToBlock(transaction newTransaction){
        this->transactionList.push_back(newTransaction);
        return this->transactionList;
    }

    void getTransaction(int index){
        cout << "transaction: " << index << endl;
        cout << "--------------------------------" << endl;
        cout << "transaction hash: " << transactionList.at(index).getTransactionHash() << endl;
        cout << "--------------------------------" << endl;
        cout << "user1: " << transactionList.at(index).getUser1PubKey() << endl;
        cout << "--------------------------------" << endl;
        cout << "user2: " << transactionList.at(index).getUser2PubKey() << endl;
        cout << "--------------------------------" << endl;
        cout << "amount sent from user1 to user2: " << transactionList.at(index).getAmountTraded() << endl;
        cout << "--------------------------------" << endl;
        cout << "time tranaction occured at: " << transactionList.at(index).getTimestamp() << endl;
        cout << "--------------------------------" << endl;
    }

    void getEntireTransactionList(){
        for(int i =0; i<this->transactionList.size(); i++){
            getTransaction(i);
        }
    }
    void printListOfTransactions(){
        ofstream fr(getBlockHash() + ".txt");
        for(int i=0; i<transactionList.size(); i++){
            fr << "transaction: " << i << endl;
            fr << "--------------------------------" << endl;
            fr << "transaction hash: " << transactionList.at(i).getTransactionHash() << endl;
            fr << "--------------------------------" << endl;
            fr << "user1: " << transactionList.at(i).getUser1PubKey() << endl;
            fr << "--------------------------------" << endl;
            fr << "user2: " << transactionList.at(i).getUser2PubKey() << endl;
            fr << "--------------------------------" << endl;
            fr << "amount sent from user1 to user2: " << transactionList.at(i).getAmountTraded() << endl;
            fr << "--------------------------------" << endl;
            fr << "time tranaction occured at: " << transactionList.at(i).getTimestamp() << endl;
            fr << "--------------------------------" << endl;
        }
        fr.close();
    }

};
