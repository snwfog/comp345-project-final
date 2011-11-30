/**
 *  Chest.h
 *  comp345-assignment-03
 *  
 *  To improve: ideally, chest should be just a simple
 *  collection like a vector kind that can be iterated
 *  through with a corresponding iterator.
 */

#ifndef CHEST_H
#define CHEST_H

#include <vector>
#include "Item.h"
#include "Observer.h"
#include "Map.h"

using std::vector;

class Chest {
    
public:
    // iteration over a vector see:
    // http://stackoverflow.com/questions/409348/iteration-over-vector-in-c
    void putItem(Item* item) {
        chestContainer.push_back(item);
        numberOfItem++;
    }
    
    Item* getItem(int index) {
        Item* item = chestContainer[index];
        removeItem(index);
        numberOfItem--;
        return item;
    }
    
    Item* peek(int index) {
        return chestContainer[index];
    }
    
    void removeItem(int index) {
        chestContainer[index] = NULL;
    }
    
    void deleteItem(int index) {
        //delete chestContainer[index];
        chestContainer[index] = NULL;
    }
    
    int getNumberOfItem() { return numberOfItem; }
    
    void setCoordinate(Coordinate* c) { chestCoordinate = c; }
    
    Coordinate* getCoordinate() { return chestCoordinate; }
    
    vector<Item*> getStach() {  return chestContainer; }
    
    int size() { return (int)(chestContainer.size()); }
    
    // observer methods
    void attachChestObserver(Observer* ob) { observer = ob; }
    
private:
    vector<class Item*> chestContainer;
    Coordinate* chestCoordinate;
    Observer* observer;
    int numberOfItem;
};

#endif
