#include "functions.h"

int main() {
	vector<user> users = generateUsers();
	vector<block> blockChain;
	block genesis;
	blockChain.push_back(genesis);
    int endProgram = 0;
    int amountOfTransactions = 0;
    do{
    int answer;
    cout << "if you would like to mine a block, enter 1" << endl;
    cout << "if you would like to make a trade between users, enter 2" << endl;
    cout << "if you would like to see the current block data, enter 3" << endl;
    cout << "if you would like to see a specific transaction within the current block, enter 4" << endl;
    cout << "if you would like the program to create a list of transactions for the last block, enter 5" << endl;
    cout << "if you would like to see a users data, please enter 6" << endl;
    cout << "enter 7 if you would like to close the program." << endl;
    cin >> answer;
    if ((answer<1) && (answer>7)){
        cout << "incorrect input, please try again" << endl;
    }
    if (answer == 1){
        int minerIndex;
        cout << "which user is mining the block? enter a number between 0 and 999" << endl;
        cin >> minerIndex;
        mine(blockChain, users.at(minerIndex));
    }
    if (answer == 2) {
        int user1Index, user2Index, amount;
        cout << "which users are trading currency? enter a number between 0 and 999 for each user" << endl;
        cout << "user1: ";
        cin >> user1Index;
        cout << "user2: ";
        cin >> user2Index;
        cout << "how much currency is being traded from user" <<  user1Index  << "to user" << user2Index << " ?" << endl;
        cin >> amount;
        cout << "amount of currency that user" << user1Index << " had before the trade: " << users.at(user1Index).getBalance() << endl;
        cout << "amount of currency that user" << user2Index << " had before the trade: " << users.at(user2Index).getBalance() << endl;
        trade(blockChain.back(), users.at(user1Index), users.at(user2Index), amount);
        amountOfTransactions++;
        cout << "trade successfull!" << endl;
        cout << "amount of currency that user" << user1Index << " has currently: " << users.at(user1Index).getBalance() << endl;
        cout << "amount of currency that user" << user2Index << " has currently: " << users.at(user2Index).getBalance() << endl;
    }
    if (answer == 3){
        cout << "current block hash: " << blockChain.back().getBlockHash() << endl;
        cout << "current blocks previous block hash: " << blockChain.back().getPrevBlockHash() << endl;
        cout << "current block index: " << blockChain.back().getIndex() << endl;
        cout << "current blocks merkel tree hash: " << blockChain.back().getMerkelTreeHash() << endl;
        cout << "current blocks version: " << blockChain.back().getVersion() << endl;
        cout << "current blocks difficulty target: " << blockChain.back().getDifficultyTarget() << endl;
        cout << "the most recent block mined was at: " << blockChain.back().getTimeStamp() << endl;
        cout << "transactions which have in this block: " << endl;
    }
    if (answer == 4){
        int index;
        cout << "type in the transaction index: ";
        cin >> index;
        if((index>=0) && (index<=amountOfTransactions)){
        blockChain.back().getTransaction(index);
        }
        else {
            cout << "transaction does not exist, please try again." << endl;
            cout << "try entering a number between 0 and " << amountOfTransactions << endl;
        }
    }
    if (answer == 5){
        blockChain.back().printListOfTransactions();
        cout << "transaction list has been printed." << endl;
    }
    if (answer == 6){
        int userIndex;
        cout << "which users data would you like to see? enter a number between 0 and 999" << endl;
        cin >> userIndex;
        cout << "user" << userIndex << "public key: " << users.at(userIndex).getPublicKey() << endl;
        cout << "user" << userIndex << "name: " << users.at(userIndex).getName() << endl;
        cout << "user" << userIndex << "balance: " << users.at(userIndex).getBalance() << endl;
    }
    if (answer == 7){
        endProgram = 1;
    }
    } while (endProgram == 0);
	return 0;
}
