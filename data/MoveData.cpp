#include "MoveData.h"
#include <fstream>

string MoveData::filename = "allMoves.bin";
vector<Move*> MoveData::cache;
bool MoveData::isCached = false;

vector<Move*>& MoveData::load() {
    if (isCached) return cache;

    ifstream inputStream;
    inputStream.open(filename, ios::binary);
    if (!inputStream) { isCached = true; return cache; }

    int moveCount;
    inputStream.read((char*)&moveCount, sizeof(int));

    for (int i = 0; i < moveCount; i++) {
        int size;
        inputStream.read((char*)&size, sizeof(int));
        char *loadedData = new char[size];
        inputStream.read(loadedData, size);
        Move *move = new Move();
        move->deserialize(loadedData);
        cache.push_back(move);
        delete[] loadedData;
    }
    isCached = true;
    return cache;
}

void MoveData::save() {
    ofstream outputStream;
    outputStream.open(filename, ios::binary);
    int moveCount = cache.size();
    outputStream.write((char*)&moveCount, sizeof(int));
    char *serialData;
    for (auto &move : cache) {
        int size;
        serialData = move->serialize(size);
        outputStream.write((char*)&size, sizeof(int));
        outputStream.write(serialData, size);
        delete serialData;
    }
}

Move *MoveData::getMove(int id) {
    load();
    for (auto currentMove : cache)
        if (currentMove->id == id)
            return currentMove;
    return nullptr;
}
