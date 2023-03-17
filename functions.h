#pragma once
#include "block.h"
#include <chrono>
#include <stdlib.h>

using namespace std::chrono;


vector<user> generateUsers() {
	vector<user> generatedUsers;
	generatedUsers.resize(1000);
	return generatedUsers;
}

void trade(block &block0, user user1, user user2, int amountTraded){
    transaction newTransaction;
    newTransaction.setUser1(user1);
    newTransaction.setUser2(user2);
    newTransaction.setAmountTraded(amountTraded);
    newTransaction.performTransaction(newTransaction.getAmountTraded());
    block0.transactionList.push_back(newTransaction);
}

block createNewBlock(block prevBlock){
    block newBlock;
    newBlock.setIndex(prevBlock.getIndex()+1);
    newBlock.takePrevBlockHash(prevBlock);
    newBlock.calculateDifficultyTarget(newBlock.getIndex());
    newBlock.calculateMerkellTreeHash(prevBlock);
    block blockCurrentlyBeingMined = newBlock;
    return blockCurrentlyBeingMined;
}


vector<block> mine(vector<block> &blockChain, user &miner){
    block newBlock = createNewBlock(blockChain.back());
    int difficulty = blockChain.back().getDifficultyTarget();
    int a=0;
    auto start = high_resolution_clock::now();
    while(sha256(to_string(a))!=sha256(to_string(newBlock.getNonce()))){
            a++;
        }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start) * 1.0 / 1000000;
    cout << "new block successfully mined! time taken: " << duration.count() << endl;
    blockChain.push_back(newBlock);
    blockChain.back().setDuration(duration.count());
    blockChain.back().setTimestamp();
    miner.rewardMiner(blockChain.back().getDifficultyTarget());
    return blockChain;
}
