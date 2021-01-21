#include "given.h"
#include "todo.h"
#include <iostream>
using namespace std;

int main()
{
    int testCaseNumber = 12;

    {
        cout << "Running test case " << testCaseNumber << "..." << endl;

        if(testCaseNumber == 1)
        {
            //description: simple test of generateMap
            int width = 5;  //map width
            int height = 4; //map height
            cout << "An empty map:" << endl;
            Node ***map = generateMap(width, height);
            printMap(map, width, height);
            cout << "Another empty map:" << endl;
            width = 5;
            height = 6;
            map = generateMap(width, height);
            printMap(map, width, height);
            //for this test case, we deliberately chose not to release the dynamic memory allocated; memory leak won't be checked for this case
        }
        else if(testCaseNumber == 2)
        {
            //description: simple test of addThing, and printMonsterCount
            int width = 5;  //map width
            int height = 4; //map height
            Node ***map = generateMap(width, height);
            cout << "adding hero: " << addThing(map, width, height, -1, 0, HERO, 1) << endl;
            cout << "adding hero: " << addThing(map, width, height, 4, 5, HERO, 1) << endl;
            cout << "adding hero: " << addThing(map, width, height, 0, 0, HERO, 1) << endl;
            cout << "adding monster: " << addThing(map, width, height, 3, 2, VAMPIRE, 1) << endl;
            printMap(map, width, height);
            cout << "Linked list nodes at (0,0): "; printLinkedList(map[0][0]);
            cout << "Linked list nodes at (3,2): "; printLinkedList(map[2][3]);
            printMonsterCount(map, width, height);
            //for this test case, we deliberately chose not to release the dynamic memory allocated; memory leak won't be checked for this case
        }
        else if(testCaseNumber == 3)
        {
            //description: advanced test of addThing, and printMonsterCount
            int width = 5;  //map width
            int height = 4; //map height
            Node ***map = generateMap(width, height);
            cout << "adding HERO: " << addThing(map, width, height, 0, 0, HERO, 1) << endl;
            cout << "adding DAGGER: " << addThing(map, width, height, 2, 1, DAGGER, 1) << endl;
            cout << "adding DAGGER: " << addThing(map, width, height, 2, 1, DAGGER, 1) << endl;
            cout << "adding SKELETON: " << addThing(map, width, height, 3, 2, SKELETON, 1) << endl;
            cout << "adding VAMPIRE: " << addThing(map, width, height, 3, 2, VAMPIRE, 3) << endl;
            cout << "adding MACE: " << addThing(map, width, height, 3, 3, MACE, 1) << endl;
            cout << "adding SWORD: " << addThing(map, width, height, 3, 3, SWORD, 3) << endl;
            cout << "adding DAGGER: " << addThing(map, width, height, 3, 3, DAGGER, 2) << endl;
            printMap(map, width, height);
            cout << "Linked list nodes at (0,0): "; printLinkedList(map[0][0]);
            cout << "Linked list nodes at (1,1): "; printLinkedList(map[1][1]);
            cout << "Linked list nodes at (2,1): "; printLinkedList(map[1][2]);
            cout << "Linked list nodes at (3,2): "; printLinkedList(map[2][3]);
            cout << "Linked list nodes at (3,3): "; printLinkedList(map[3][3]);
            printMonsterCount(map, width, height);
            //for this test case, we deliberately chose not to release the dynamic memory allocated; memory leak won't be checked for this case
        }
        else if(testCaseNumber == 4)
        {
            //description: simple test of removeThing (on a cell with 1 type of thing)
            int width = 5;  //map width
            int height = 4; //map height
            Node ***map = generateMap(width, height);
            addThing(map, width, height, 0, 0, HERO, 1);
            addThing(map, width, height, 2, 1, DAGGER, 1);
            addThing(map, width, height, 2, 1, DAGGER, 1);
            addThing(map, width, height, 3, 2, SKELETON, 1);
            addThing(map, width, height, 3, 2, VAMPIRE, 3);
            addThing(map, width, height, 3, 3, MACE, 1);
            addThing(map, width, height, 3, 3, SWORD, 3);
            addThing(map, width, height, 3, 3, DAGGER, 2);
            cout << "removeing DAGGER: " << removeThing(map, width, height, 2, 1, DAGGER, 1) << endl;
            printMap(map, width, height);
            cout << "Linked list nodes at (0,0): "; printLinkedList(map[0][0]);
            cout << "Linked list nodes at (1,1): "; printLinkedList(map[1][1]);
            cout << "Linked list nodes at (2,1): "; printLinkedList(map[1][2]);
            cout << "Linked list nodes at (3,2): "; printLinkedList(map[2][3]);
            cout << "Linked list nodes at (3,3): "; printLinkedList(map[3][3]);
            cout << "removeing DAGGER again: " << removeThing(map, width, height, 2, 1, DAGGER, 1) << endl;
            printMap(map, width, height);
            cout << "Linked list nodes at (0,0): "; printLinkedList(map[0][0]);
            cout << "Linked list nodes at (1,1): "; printLinkedList(map[1][1]);
            cout << "Linked list nodes at (2,1): "; printLinkedList(map[1][2]);
            cout << "Linked list nodes at (3,2): "; printLinkedList(map[2][3]);
            cout << "Linked list nodes at (3,3): "; printLinkedList(map[3][3]);
            cout << "removeing DAGGER one more time: " << removeThing(map, width, height, 2, 1, DAGGER, 1) << endl;
            printMap(map, width, height);
            cout << "Linked list nodes at (0,0): "; printLinkedList(map[0][0]);
            cout << "Linked list nodes at (1,1): "; printLinkedList(map[1][1]);
            cout << "Linked list nodes at (2,1): "; printLinkedList(map[1][2]);
            cout << "Linked list nodes at (3,2): "; printLinkedList(map[2][3]);
            cout << "Linked list nodes at (3,3): "; printLinkedList(map[3][3]);
            //for this test case, we deliberately chose not to release the dynamic memory allocated; memory leak won't be checked for this case
        }
        else if(testCaseNumber == 5)
        {
            //description: simple test of moveHero and printHeroStatus
            int width = 5;  //map width
            int height = 4; //map height
            HeroStatus heroStatus;
            Node ***map = generateMap(width, height);
            addThing(map, width, height, 0, 0, HERO, 1);
            addThing(map, width, height, 2, 1, DAGGER, 1);
            addThing(map, width, height, 2, 1, DAGGER, 1);
            addThing(map, width, height, 3, 2, SKELETON, 1);
            addThing(map, width, height, 3, 2, VAMPIRE, 3);
            addThing(map, width, height, 3, 3, MACE, 1);
            addThing(map, width, height, 3, 3, SWORD, 3);
            addThing(map, width, height, 3, 3, DAGGER, 2);
            printMap(map, width, height);
            printHeroStatus(heroStatus);
            cout << "moveHero: " << moveHero('a', map, width, height, heroStatus) << endl;
            cout << "moveHero: " << moveHero('w', map, width, height, heroStatus) << endl;
            cout << "moveHero: " << moveHero('d', map, width, height, heroStatus) << endl;
            printMap(map, width, height);
            printHeroStatus(heroStatus);
            cout << "Linked list nodes at (0,0): "; printLinkedList(map[0][0]);
            cout << "Linked list nodes at (1,0): "; printLinkedList(map[0][1]);
            cout << "Linked list nodes at (1,1): "; printLinkedList(map[1][1]);
            cout << "Linked list nodes at (2,1): "; printLinkedList(map[1][2]);
            cout << "Linked list nodes at (3,2): "; printLinkedList(map[2][3]);
            cout << "Linked list nodes at (3,3): "; printLinkedList(map[3][3]);
            //for this test case, we deliberately chose not to release the dynamic memory allocated; memory leak won't be checked for this case
        }
        else if(testCaseNumber == 6)
        {
            //description: test of moving hero to get weapons
            int width = 5;  //map width
            int height = 4; //map height
            HeroStatus heroStatus;
            Node ***map = generateMap(width, height);
            addThing(map, width, height, 0, 0, HERO, 1);
            addThing(map, width, height, 2, 1, DAGGER, 1);
            addThing(map, width, height, 2, 1, DAGGER, 1);
            addThing(map, width, height, 3, 2, SKELETON, 1);
            addThing(map, width, height, 3, 2, VAMPIRE, 3);
            addThing(map, width, height, 3, 3, MACE, 1);
            addThing(map, width, height, 3, 3, SWORD, 3);
            addThing(map, width, height, 3, 3, DAGGER, 2);
            printMap(map, width, height);
            printHeroStatus(heroStatus);
            cout << "moveHero: " << moveHero('d', map, width, height, heroStatus) << endl;
            cout << "moveHero: " << moveHero('d', map, width, height, heroStatus) << endl;
            cout << "moveHero: " << moveHero('s', map, width, height, heroStatus) << endl; //takes 2 daggers
            printMap(map, width, height);
            printHeroStatus(heroStatus);
            cout << "Linked list nodes at (0,0): "; printLinkedList(map[0][0]);
            cout << "Linked list nodes at (1,0): "; printLinkedList(map[0][1]);
            cout << "Linked list nodes at (1,1): "; printLinkedList(map[1][1]);
            cout << "Linked list nodes at (2,1): "; printLinkedList(map[1][2]);
            cout << "Linked list nodes at (3,2): "; printLinkedList(map[2][3]);
            cout << "Linked list nodes at (3,3): "; printLinkedList(map[3][3]);
            cout << "moveHero: " << moveHero('s', map, width, height, heroStatus) << endl;
            cout << "moveHero: " << moveHero('s', map, width, height, heroStatus) << endl;
            cout << "moveHero: " << moveHero('d', map, width, height, heroStatus) << endl; //gets 1 mace, 3 sowrds, and 2 daggers
            printMap(map, width, height);
            printHeroStatus(heroStatus);
            cout << "Linked list nodes at (0,0): "; printLinkedList(map[0][0]);
            cout << "Linked list nodes at (1,0): "; printLinkedList(map[0][1]);
            cout << "Linked list nodes at (1,1): "; printLinkedList(map[1][1]);
            cout << "Linked list nodes at (2,1): "; printLinkedList(map[1][2]);
            cout << "Linked list nodes at (3,2): "; printLinkedList(map[2][3]);
            cout << "Linked list nodes at (3,3): "; printLinkedList(map[3][3]);
            //for this test case, we deliberately chose not to release the dynamic memory allocated; memory leak won't be checked for this case
        }
        else if(testCaseNumber == 7)
        {
            //description: test of moving hero to get weapons, encounter monsters, and live
            int width = 5;  //map width
            int height = 4; //map height
            HeroStatus heroStatus;
            Node ***map = generateMap(width, height);
            addThing(map, width, height, 0, 0, HERO, 1);
            addThing(map, width, height, 2, 1, DAGGER, 1);
            addThing(map, width, height, 2, 1, DAGGER, 1);
            addThing(map, width, height, 3, 2, SKELETON, 1);
            addThing(map, width, height, 3, 2, VAMPIRE, 3);
            addThing(map, width, height, 3, 3, MACE, 1);
            addThing(map, width, height, 3, 3, SWORD, 3);
            addThing(map, width, height, 3, 3, DAGGER, 2);
            printMap(map, width, height);
            printHeroStatus(heroStatus);
            cout << "moveHero: " << moveHero('d', map, width, height, heroStatus) << endl;
            cout << "moveHero: " << moveHero('d', map, width, height, heroStatus) << endl;
            cout << "moveHero: " << moveHero('s', map, width, height, heroStatus) << endl; //get weapons
            printMap(map, width, height);
            printHeroStatus(heroStatus);
            cout << "moveHero: " << moveHero('s', map, width, height, heroStatus) << endl;
            cout << "moveHero: " << moveHero('s', map, width, height, heroStatus) << endl;
            cout << "moveHero: " << moveHero('d', map, width, height, heroStatus) << endl; //get weapons
            printMap(map, width, height);
            printHeroStatus(heroStatus);
            cout << "moveHero: " << moveHero('w', map, width, height, heroStatus) << endl; //encounter monsters
            printMap(map, width, height);
            printHeroStatus(heroStatus);
            cout << "Linked list nodes at (0,0): "; printLinkedList(map[0][0]);
            cout << "Linked list nodes at (1,0): "; printLinkedList(map[0][1]);
            cout << "Linked list nodes at (1,1): "; printLinkedList(map[1][1]);
            cout << "Linked list nodes at (2,1): "; printLinkedList(map[1][2]);
            cout << "Linked list nodes at (3,2): "; printLinkedList(map[2][3]);
            cout << "Linked list nodes at (3,3): "; printLinkedList(map[3][3]);
            cout << "Hero is " << (heroStatus.alive?"alive":"dead") << endl;
            //for this test case, we deliberately chose not to release the dynamic memory allocated; memory leak won't be checked for this case
        }
        else if(testCaseNumber == 8)
        {
            //description: test of moving hero to get weapons, encounter monsters, and die; check getMonsterCount as well
            int width = 5;  //map width
            int height = 4; //map height
            HeroStatus heroStatus;
            Node ***map = generateMap(width, height);
            addThing(map, width, height, 0, 0, HERO, 1);
            addThing(map, width, height, 1, 0, SWORD, 1);
            addThing(map, width, height, 1, 0, MACE, 1);
            addThing(map, width, height, 1, 1, SKELETON, 1);
            addThing(map, width, height, 1, 1, VAMPIRE, 1);
            printMap(map, width, height);
            printHeroStatus(heroStatus);
            cout << "getMonsterCount returns " << getMonsterCount(map, width, height) << endl;
            cout << "Hero is " << (heroStatus.alive?"alive":"dead") << endl;
            cout << "moveHero: " << moveHero('d', map, width, height, heroStatus) << endl; //get weapons
            cout << "moveHero: " << moveHero('s', map, width, height, heroStatus) << endl; //encounter monsters (not enough appropriate weapons to kill them all)
            printMap(map, width, height);
            printHeroStatus(heroStatus);
            cout << "Linked list nodes at (0,0): "; printLinkedList(map[0][0]);
            cout << "Linked list nodes at (0,1): "; printLinkedList(map[1][0]);
            cout << "Linked list nodes at (1,0): "; printLinkedList(map[0][1]);
            cout << "Linked list nodes at (1,1): "; printLinkedList(map[1][1]);
            cout << "Hero is " << (heroStatus.alive?"alive":"dead") << endl;
            cout << "getMonsterCount returns " << getMonsterCount(map, width, height) << endl;
            //for this test case, we deliberately chose not to release the dynamic memory allocated; memory leak won't be checked for this case
        }
        else if(testCaseNumber == 9)
        {
            //description: simple memory leak checking: just to delete empty maps and a linked list
            int width = 5;  //map width
            int height = 4; //map height
            cout << "An empty map:" << endl;
            Node ***map = generateMap(width, height);
            printMap(map, width, height);
            cout << "Deleting map..." << endl;
            deleteMap(map, width, height);
            cout << "Done!" << endl;
            cout << "Another empty map:" << endl;
            width = 5;
            height = 6;
            map = generateMap(width, height);
            printMap(map, width, height);
            cout << "Deleting map..." << endl;
            deleteMap(map, width, height);
            cout << "Done!" << endl;
            Node* node1 = new Node;
            Node* node2 = new Node;
            node1->next = node2;
            cout << "Deleting a linked list of 2 nodes..." << endl;
            deleteLinkedList(node1);
            cout << "Done!" << endl;
            //for this test case, we WILL check for memory leak on Zinc. See the new Zinc submission guide for details.
        }
        else if(testCaseNumber == 10)
        {
            //description: memory leak checking for a simple test of removeThing (on a cell with 1 type of thing)
            int width = 5;  //map width
            int height = 4; //map height
            Node ***map = generateMap(width, height);
            addThing(map, width, height, 0, 0, HERO, 1);
            addThing(map, width, height, 2, 1, DAGGER, 1);
            addThing(map, width, height, 2, 1, DAGGER, 1);
            addThing(map, width, height, 3, 2, SKELETON, 1);
            addThing(map, width, height, 3, 2, VAMPIRE, 3);
            addThing(map, width, height, 3, 3, MACE, 1);
            addThing(map, width, height, 3, 3, SWORD, 3);
            addThing(map, width, height, 3, 3, DAGGER, 2);
            cout << "removeing DAGGER: " << removeThing(map, width, height, 2, 1, DAGGER, 1) << endl;
            printMap(map, width, height);
            cout << "Linked list nodes at (0,0): "; printLinkedList(map[0][0]);
            cout << "Linked list nodes at (1,1): "; printLinkedList(map[1][1]);
            cout << "Linked list nodes at (2,1): "; printLinkedList(map[1][2]);
            cout << "Linked list nodes at (3,2): "; printLinkedList(map[2][3]);
            cout << "Linked list nodes at (3,3): "; printLinkedList(map[3][3]);
            cout << "removeing DAGGER again: " << removeThing(map, width, height, 2, 1, DAGGER, 1) << endl;
            printMap(map, width, height);
            cout << "Linked list nodes at (0,0): "; printLinkedList(map[0][0]);
            cout << "Linked list nodes at (1,1): "; printLinkedList(map[1][1]);
            cout << "Linked list nodes at (2,1): "; printLinkedList(map[1][2]);
            cout << "Linked list nodes at (3,2): "; printLinkedList(map[2][3]);
            cout << "Linked list nodes at (3,3): "; printLinkedList(map[3][3]);
            cout << "removeing DAGGER one more time: " << removeThing(map, width, height, 2, 1, DAGGER, 1) << endl;
            printMap(map, width, height);
            cout << "Linked list nodes at (0,0): "; printLinkedList(map[0][0]);
            cout << "Linked list nodes at (1,1): "; printLinkedList(map[1][1]);
            cout << "Linked list nodes at (2,1): "; printLinkedList(map[1][2]);
            cout << "Linked list nodes at (3,2): "; printLinkedList(map[2][3]);
            cout << "Linked list nodes at (3,3): "; printLinkedList(map[3][3]);
            cout << "Deleting map..." << endl;
            deleteMap(map, width, height);
            cout << "Done!" << endl;
            //for this test case, we WILL check for memory leak on Zinc. See the new Zinc submission guide for details.
        }
        else if(testCaseNumber == 11)
        {
            //description: memory leak checking after removing all things on a complicated cell with 3 types of thing
            int width = 5;  //map width
            int height = 4; //map height
            HeroStatus heroStatus;
            Node ***map = generateMap(width, height);
            addThing(map, width, height, 0, 0, HERO, 1);
            addThing(map, width, height, 2, 1, DAGGER, 1);
            addThing(map, width, height, 2, 1, DAGGER, 1);
            addThing(map, width, height, 3, 2, SKELETON, 1);
            addThing(map, width, height, 3, 2, VAMPIRE, 3);
            addThing(map, width, height, 3, 3, MACE, 1);
            addThing(map, width, height, 3, 3, SWORD, 3);
            addThing(map, width, height, 3, 3, DAGGER, 2);
            printMap(map, width, height);
            cout << "Linked list nodes at (3,3): "; printLinkedList(map[3][3]);
            cout << "remove dagger: " << removeThing(map, width, height, 3, 3, DAGGER, 3) << endl;
            cout << "Linked list nodes at (3,3): "; printLinkedList(map[3][3]);
            cout << "remove dagger: " << removeThing(map, width, height, 3, 3, DAGGER, 2) << endl;
            cout << "Linked list nodes at (3,3): "; printLinkedList(map[3][3]);
            cout << "remove sword: " << removeThing(map, width, height, 3, 3, SWORD, 1) << endl;
            cout << "Linked list nodes at (3,3): "; printLinkedList(map[3][3]);
            cout << "remove sword: " << removeThing(map, width, height, 3, 3, SWORD, 2) << endl;
            cout << "Linked list nodes at (3,3): "; printLinkedList(map[3][3]);
            cout << "remove mace: " << removeThing(map, width, height, 3, 3, MACE, 1) << endl;
            cout << "Linked list nodes at (3,3): "; printLinkedList(map[3][3]);
            printMap(map, width, height);
            cout << "Deleting map..." << endl;
            deleteMap(map, width, height);
            cout << "Done!" << endl;
            //for this test case, we WILL check for memory leak on Zinc. See the new Zinc submission guide for details.
        }
        else if(testCaseNumber == 12)
        {
            //description: memory leak checking after moving the hero to get weapons and kill monsters
            int width = 5;  //map width
            int height = 4; //map height
            HeroStatus heroStatus;
            Node ***map = generateMap(width, height);
            addThing(map, width, height, 0, 0, HERO, 1);
            addThing(map, width, height, 1, 0, SWORD, 1);
            addThing(map, width, height, 1, 0, MACE, 1);
            addThing(map, width, height, 1, 0, DAGGER, 1);
            addThing(map, width, height, 1, 1, SKELETON, 1);
            addThing(map, width, height, 1, 1, VAMPIRE, 1);
            addThing(map, width, height, 2, 2, VAMPIRE, 1);
            printMap(map, width, height);
            cout << "moveHero: " << moveHero('d', map, width, height, heroStatus) << endl;
            cout << "moveHero: " << moveHero('s', map, width, height, heroStatus) << endl;
            printMap(map, width, height);
            printHeroStatus(heroStatus);
            cout << "Linked list nodes at (0,0): "; printLinkedList(map[0][0]);
            cout << "Linked list nodes at (0,1): "; printLinkedList(map[1][0]);
            cout << "Linked list nodes at (1,0): "; printLinkedList(map[0][1]);
            cout << "Linked list nodes at (1,1): "; printLinkedList(map[1][1]);
            cout << "Hero is " << (heroStatus.alive?"alive":"dead") << endl;
            cout << "getMonsterCount returns " << getMonsterCount(map, width, height) << endl;
            cout << "Deleting map..." << endl;
            deleteMap(map, width, height);
            cout << "Done!" << endl;
            //for this test case, we WILL check for memory leak on Zinc. See the new Zinc submission guide for details.
        }
        else if(testCaseNumber == 13)
        {
            //description: advanced test of addThing (on a cell with 3 types of thing); add to 1st item several times
            int width = 5;  //map width
            int height = 4; //map height
            Node ***map = generateMap(width, height);
            addThing(map, width, height, 0, 0, HERO, 1);
            addThing(map, width, height, 2, 2, MACE, 3);
            addThing(map, width, height, 2, 2, SWORD, 3);
            addThing(map, width, height, 2, 2, DAGGER, 3);
            addThing(map, width, height, 3, 3, MACE, 3);
            addThing(map, width, height, 3, 3, SWORD, 3);
            addThing(map, width, height, 3, 3, DAGGER, 3);
            cout << "adding more MACE: " << addThing(map, width, height, 3, 3, MACE, 1) << endl;
            printMap(map, width, height);
            cout << "Linked list nodes at (0,0): "; printLinkedList(map[0][0]);
            cout << "Linked list nodes at (2,2): "; printLinkedList(map[2][2]);
            cout << "Linked list nodes at (3,3): "; printLinkedList(map[3][3]);
            cout << "adding more MACE: " << addThing(map, width, height, 3, 3, MACE, 2) << endl;
            printMap(map, width, height);
            cout << "Linked list nodes at (0,0): "; printLinkedList(map[0][0]);
            cout << "Linked list nodes at (2,2): "; printLinkedList(map[2][2]);
            cout << "Linked list nodes at (3,3): "; printLinkedList(map[3][3]);
            //for this test case, we deliberately chose not to release the dynamic memory allocated; memory leak won't be checked for this case
        }
        else if(testCaseNumber == 14)
        {
            //description: advanced test of addThing (on a cell with 3 types of thing); add to 2nd item several times
            int width = 5;  //map width
            int height = 4; //map height
            Node ***map = generateMap(width, height);
            addThing(map, width, height, 0, 0, HERO, 1);
            addThing(map, width, height, 2, 2, MACE, 3);
            addThing(map, width, height, 2, 2, SWORD, 3);
            addThing(map, width, height, 2, 2, DAGGER, 3);
            addThing(map, width, height, 3, 3, MACE, 3);
            addThing(map, width, height, 3, 3, SWORD, 3);
            addThing(map, width, height, 3, 3, DAGGER, 3);
            cout << "adding more SWORD: " << addThing(map, width, height, 3, 3, SWORD, 1) << endl;
            printMap(map, width, height);
            cout << "Linked list nodes at (0,0): "; printLinkedList(map[0][0]);
            cout << "Linked list nodes at (2,2): "; printLinkedList(map[2][2]);
            cout << "Linked list nodes at (3,3): "; printLinkedList(map[3][3]);
            cout << "adding more SWORD: " << addThing(map, width, height, 3, 3, SWORD, 2) << endl;
            printMap(map, width, height);
            cout << "Linked list nodes at (0,0): "; printLinkedList(map[0][0]);
            cout << "Linked list nodes at (2,2): "; printLinkedList(map[2][2]);
            cout << "Linked list nodes at (3,3): "; printLinkedList(map[3][3]);
            //for this test case, we deliberately chose not to release the dynamic memory allocated; memory leak won't be checked for this case
        }
        else if(testCaseNumber == 15)
        {
            //description: advanced test of addThing (on a cell with 3 types of thing); add to 3rd item several times
            int width = 5;  //map width
            int height = 4; //map height
            Node ***map = generateMap(width, height);
            addThing(map, width, height, 0, 0, HERO, 1);
            addThing(map, width, height, 2, 2, MACE, 3);
            addThing(map, width, height, 2, 2, SWORD, 3);
            addThing(map, width, height, 2, 2, DAGGER, 3);
            addThing(map, width, height, 3, 3, MACE, 3);
            addThing(map, width, height, 3, 3, SWORD, 3);
            addThing(map, width, height, 3, 3, DAGGER, 3);
            cout << "adding more DAGGER: " << addThing(map, width, height, 3, 3, DAGGER, 1) << endl;
            printMap(map, width, height);
            cout << "Linked list nodes at (0,0): "; printLinkedList(map[0][0]);
            cout << "Linked list nodes at (2,2): "; printLinkedList(map[2][2]);
            cout << "Linked list nodes at (3,3): "; printLinkedList(map[3][3]);
            cout << "adding more DAGGER: " << addThing(map, width, height, 3, 3, DAGGER, 2) << endl;
            printMap(map, width, height);
            cout << "Linked list nodes at (0,0): "; printLinkedList(map[0][0]);
            cout << "Linked list nodes at (2,2): "; printLinkedList(map[2][2]);
            cout << "Linked list nodes at (3,3): "; printLinkedList(map[3][3]);
            //for this test case, we deliberately chose not to release the dynamic memory allocated; memory leak won't be checked for this case
        }
        else if(testCaseNumber == 16)
        {
            //description: advanced test of removeThing (on a cell with 3 types of thing); delete 1st item
            int width = 5;  //map width
            int height = 4; //map height
            Node ***map = generateMap(width, height);
            addThing(map, width, height, 0, 0, HERO, 1);
            addThing(map, width, height, 2, 2, MACE, 3);
            addThing(map, width, height, 2, 2, SWORD, 3);
            addThing(map, width, height, 2, 2, DAGGER, 3);
            addThing(map, width, height, 3, 3, MACE, 3);
            addThing(map, width, height, 3, 3, SWORD, 3);
            addThing(map, width, height, 3, 3, DAGGER, 3);
            cout << "removeing MACE: " << removeThing(map, width, height, 3, 3, MACE, 1) << endl;
            printMap(map, width, height);
            cout << "Linked list nodes at (0,0): "; printLinkedList(map[0][0]);
            cout << "Linked list nodes at (2,2): "; printLinkedList(map[2][2]);
            cout << "Linked list nodes at (3,3): "; printLinkedList(map[3][3]);
            cout << "removeing MACE: " << removeThing(map, width, height, 3, 3, MACE, 2) << endl;
            printMap(map, width, height);
            cout << "Linked list nodes at (0,0): "; printLinkedList(map[0][0]);
            cout << "Linked list nodes at (2,2): "; printLinkedList(map[2][2]);
            cout << "Linked list nodes at (3,3): "; printLinkedList(map[3][3]);
            cout << "removeing MACE: " << removeThing(map, width, height, 3, 3, MACE, 2) << endl;
            printMap(map, width, height);
            cout << "Linked list nodes at (0,0): "; printLinkedList(map[0][0]);
            cout << "Linked list nodes at (2,2): "; printLinkedList(map[2][2]);
            cout << "Linked list nodes at (3,3): "; printLinkedList(map[3][3]);
            //for this test case, we deliberately chose not to release the dynamic memory allocated; memory leak won't be checked for this case
        }
        else if(testCaseNumber == 17)
        {
            //description: advanced test of removeThing (on a cell with 3 types of thing); delete 2nd item
            int width = 5;  //map width
            int height = 4; //map height
            Node ***map = generateMap(width, height);
            addThing(map, width, height, 0, 0, HERO, 1);
            addThing(map, width, height, 2, 2, MACE, 3);
            addThing(map, width, height, 2, 2, SWORD, 3);
            addThing(map, width, height, 2, 2, DAGGER, 3);
            addThing(map, width, height, 3, 3, MACE, 3);
            addThing(map, width, height, 3, 3, SWORD, 3);
            addThing(map, width, height, 3, 3, DAGGER, 3);
            cout << "removeing SWORD: " << removeThing(map, width, height, 3, 3, SWORD, 1) << endl;
            printMap(map, width, height);
            cout << "Linked list nodes at (0,0): "; printLinkedList(map[0][0]);
            cout << "Linked list nodes at (2,2): "; printLinkedList(map[2][2]);
            cout << "Linked list nodes at (3,3): "; printLinkedList(map[3][3]);
            cout << "removeing SWORD: " << removeThing(map, width, height, 3, 3, SWORD, 2) << endl;
            printMap(map, width, height);
            cout << "Linked list nodes at (0,0): "; printLinkedList(map[0][0]);
            cout << "Linked list nodes at (2,2): "; printLinkedList(map[2][2]);
            cout << "Linked list nodes at (3,3): "; printLinkedList(map[3][3]);
            cout << "removeing SWORD: " << removeThing(map, width, height, 3, 3, SWORD, 2) << endl;
            printMap(map, width, height);
            cout << "Linked list nodes at (0,0): "; printLinkedList(map[0][0]);
            cout << "Linked list nodes at (2,2): "; printLinkedList(map[2][2]);
            cout << "Linked list nodes at (3,3): "; printLinkedList(map[3][3]);
            //for this test case, we deliberately chose not to release the dynamic memory allocated; memory leak won't be checked for this case
        }
        else if(testCaseNumber == 18)
        {
            //description: advanced test of removeThing (on a cell with 3 types of thing); delete 3rd item
            int width = 5;  //map width
            int height = 4; //map height
            Node ***map = generateMap(width, height);
            addThing(map, width, height, 0, 0, HERO, 1);
            addThing(map, width, height, 2, 2, MACE, 3);
            addThing(map, width, height, 2, 2, SWORD, 3);
            addThing(map, width, height, 2, 2, DAGGER, 3);
            addThing(map, width, height, 3, 3, MACE, 3);
            addThing(map, width, height, 3, 3, SWORD, 3);
            addThing(map, width, height, 3, 3, DAGGER, 3);
            cout << "removeing DAGGER: " << removeThing(map, width, height, 3, 3, DAGGER, 1) << endl;
            printMap(map, width, height);
            cout << "Linked list nodes at (0,0): "; printLinkedList(map[0][0]);
            cout << "Linked list nodes at (2,2): "; printLinkedList(map[2][2]);
            cout << "Linked list nodes at (3,3): "; printLinkedList(map[3][3]);
            cout << "removeing DAGGER: " << removeThing(map, width, height, 3, 3, DAGGER, 2) << endl;
            printMap(map, width, height);
            cout << "Linked list nodes at (0,0): "; printLinkedList(map[0][0]);
            cout << "Linked list nodes at (2,2): "; printLinkedList(map[2][2]);
            cout << "Linked list nodes at (3,3): "; printLinkedList(map[3][3]);
            cout << "removeing DAGGER: " << removeThing(map, width, height, 3, 3, DAGGER, 2) << endl;
            printMap(map, width, height);
            cout << "Linked list nodes at (0,0): "; printLinkedList(map[0][0]);
            cout << "Linked list nodes at (2,2): "; printLinkedList(map[2][2]);
            cout << "Linked list nodes at (3,3): "; printLinkedList(map[3][3]);
            //for this test case, we deliberately chose not to release the dynamic memory allocated; memory leak won't be checked for this case
        }
        else if(testCaseNumber == 19)
        {
            //description: moving hero a lot and hitting the boundaries
            int width = 2;  //map width
            int height = 2; //map height
            HeroStatus heroStatus;
            Node ***map = generateMap(width, height);
            addThing(map, width, height, 0, 0, HERO, 1);
            for(int i=0;i<4;i++)
                cout << "moveHero: " << moveHero('a', map, width, height, heroStatus) << endl;
            printMap(map, width, height);
            cout << "Linked list nodes at (0,0): "; printLinkedList(map[0][0]);
            cout << "Linked list nodes at (0,1): "; printLinkedList(map[1][0]);
            cout << "Linked list nodes at (1,0): "; printLinkedList(map[0][1]);
            cout << "Linked list nodes at (1,1): "; printLinkedList(map[1][1]);
            for(int i=0;i<4;i++)
                cout << "moveHero: " << moveHero('s', map, width, height, heroStatus) << endl;
            printMap(map, width, height);
            cout << "Linked list nodes at (0,0): "; printLinkedList(map[0][0]);
            cout << "Linked list nodes at (0,1): "; printLinkedList(map[1][0]);
            cout << "Linked list nodes at (1,0): "; printLinkedList(map[0][1]);
            cout << "Linked list nodes at (1,1): "; printLinkedList(map[1][1]);
            for(int i=0;i<4;i++)
                cout << "moveHero: " << moveHero('d', map, width, height, heroStatus) << endl;
            printMap(map, width, height);
            cout << "Linked list nodes at (0,0): "; printLinkedList(map[0][0]);
            cout << "Linked list nodes at (0,1): "; printLinkedList(map[1][0]);
            cout << "Linked list nodes at (1,0): "; printLinkedList(map[0][1]);
            cout << "Linked list nodes at (1,1): "; printLinkedList(map[1][1]);
            for(int i=0;i<4;i++)
                cout << "moveHero: " << moveHero('w', map, width, height, heroStatus) << endl;
            printMap(map, width, height);
            cout << "Linked list nodes at (0,0): "; printLinkedList(map[0][0]);
            cout << "Linked list nodes at (0,1): "; printLinkedList(map[1][0]);
            cout << "Linked list nodes at (1,0): "; printLinkedList(map[0][1]);
            cout << "Linked list nodes at (1,1): "; printLinkedList(map[1][1]);
            //for this test case, we deliberately chose not to release the dynamic memory allocated; memory leak won't be checked for this case
        }
        else if(testCaseNumber == 20)
        {
            //description: encounter monsters (just enough weapons to kill all)
            int width = 3;  //map width
            int height = 1; //map height
            HeroStatus heroStatus;
            Node ***map = generateMap(width, height);
            addThing(map, width, height, 0, 0, HERO, 1);
            addThing(map, width, height, 1, 0, MACE, 3);
            addThing(map, width, height, 1, 0, DAGGER, 4);
            addThing(map, width, height, 1, 0, SWORD, 5);
            addThing(map, width, height, 2, 0, SKELETON, 3);
            addThing(map, width, height, 2, 0, VAMPIRE, 4);
            addThing(map, width, height, 2, 0, DRAGON, 5);
            cout << "moveHero: " << moveHero('d', map, width, height, heroStatus) << endl;
            printMap(map, width, height);
            printHeroStatus(heroStatus);
            cout << "Hero is " << (heroStatus.alive?"alive":"dead") << endl;
            cout << "Linked list nodes at (0,0): "; printLinkedList(map[0][0]);
            cout << "Linked list nodes at (1,0): "; printLinkedList(map[0][1]);
            cout << "Linked list nodes at (2,0): "; printLinkedList(map[0][2]);
            cout << "moveHero: " << moveHero('d', map, width, height, heroStatus) << endl;
            printMap(map, width, height);
            printHeroStatus(heroStatus);
            cout << "Hero is " << (heroStatus.alive?"alive":"dead") << endl;
            cout << "Linked list nodes at (0,0): "; printLinkedList(map[0][0]);
            cout << "Linked list nodes at (1,0): "; printLinkedList(map[0][1]);
            cout << "Linked list nodes at (2,0): "; printLinkedList(map[0][2]);
            //for this test case, we deliberately chose not to release the dynamic memory allocated; memory leak won't be checked for this case
        }
        else if(testCaseNumber == 21)
        {
            //description: encounter monsters (missing 1 weapon to kill 1st monster)
            int width = 3;  //map width
            int height = 1; //map height
            HeroStatus heroStatus;
            Node ***map = generateMap(width, height);
            addThing(map, width, height, 0, 0, HERO, 1);
            addThing(map, width, height, 1, 0, MACE, 2);
            addThing(map, width, height, 1, 0, DAGGER, 4);
            addThing(map, width, height, 1, 0, SWORD, 5);
            addThing(map, width, height, 2, 0, SKELETON, 3);
            addThing(map, width, height, 2, 0, VAMPIRE, 4);
            addThing(map, width, height, 2, 0, DRAGON, 5);
            cout << "moveHero: " << moveHero('d', map, width, height, heroStatus) << endl;
            printMap(map, width, height);
            printHeroStatus(heroStatus);
            cout << "Hero is " << (heroStatus.alive?"alive":"dead") << endl;
            cout << "Linked list nodes at (0,0): "; printLinkedList(map[0][0]);
            cout << "Linked list nodes at (1,0): "; printLinkedList(map[0][1]);
            cout << "Linked list nodes at (2,0): "; printLinkedList(map[0][2]);
            cout << "moveHero: " << moveHero('d', map, width, height, heroStatus) << endl;
            printMap(map, width, height);
            printHeroStatus(heroStatus);
            cout << "Hero is " << (heroStatus.alive?"alive":"dead") << endl;
            cout << "Linked list nodes at (0,0): "; printLinkedList(map[0][0]);
            cout << "Linked list nodes at (1,0): "; printLinkedList(map[0][1]);
            cout << "Linked list nodes at (2,0): "; printLinkedList(map[0][2]);
            //for this test case, we deliberately chose not to release the dynamic memory allocated; memory leak won't be checked for this case
        }
        else if(testCaseNumber == 22)
        {
            //description: encounter monsters (missing 1 weapon to kill 2nd monster)
            int width = 3;  //map width
            int height = 1; //map height
            HeroStatus heroStatus;
            Node ***map = generateMap(width, height);
            addThing(map, width, height, 0, 0, HERO, 1);
            addThing(map, width, height, 1, 0, MACE, 3);
            addThing(map, width, height, 1, 0, DAGGER, 3);
            addThing(map, width, height, 1, 0, SWORD, 5);
            addThing(map, width, height, 2, 0, SKELETON, 3);
            addThing(map, width, height, 2, 0, VAMPIRE, 4);
            addThing(map, width, height, 2, 0, DRAGON, 5);
            cout << "moveHero: " << moveHero('d', map, width, height, heroStatus) << endl;
            printMap(map, width, height);
            printHeroStatus(heroStatus);
            cout << "Hero is " << (heroStatus.alive?"alive":"dead") << endl;
            cout << "Linked list nodes at (0,0): "; printLinkedList(map[0][0]);
            cout << "Linked list nodes at (1,0): "; printLinkedList(map[0][1]);
            cout << "Linked list nodes at (2,0): "; printLinkedList(map[0][2]);
            cout << "moveHero: " << moveHero('d', map, width, height, heroStatus) << endl;
            printMap(map, width, height);
            printHeroStatus(heroStatus);
            cout << "Hero is " << (heroStatus.alive?"alive":"dead") << endl;
            cout << "Linked list nodes at (0,0): "; printLinkedList(map[0][0]);
            cout << "Linked list nodes at (1,0): "; printLinkedList(map[0][1]);
            cout << "Linked list nodes at (2,0): "; printLinkedList(map[0][2]);
            //for this test case, we deliberately chose not to release the dynamic memory allocated; memory leak won't be checked for this case
        }
        else if(testCaseNumber == 23)
        {
            //description: encounter monsters (missing 1 weapon to kill 3rd monster)
            int width = 3;  //map width
            int height = 1; //map height
            HeroStatus heroStatus;
            Node ***map = generateMap(width, height);
            addThing(map, width, height, 0, 0, HERO, 1);
            addThing(map, width, height, 1, 0, MACE, 3);
            addThing(map, width, height, 1, 0, DAGGER, 4);
            addThing(map, width, height, 1, 0, SWORD, 4);
            addThing(map, width, height, 2, 0, SKELETON, 3);
            addThing(map, width, height, 2, 0, VAMPIRE, 4);
            addThing(map, width, height, 2, 0, DRAGON, 5);
            cout << "moveHero: " << moveHero('d', map, width, height, heroStatus) << endl;
            printMap(map, width, height);
            printHeroStatus(heroStatus);
            cout << "Hero is " << (heroStatus.alive?"alive":"dead") << endl;
            cout << "Linked list nodes at (0,0): "; printLinkedList(map[0][0]);
            cout << "Linked list nodes at (1,0): "; printLinkedList(map[0][1]);
            cout << "Linked list nodes at (2,0): "; printLinkedList(map[0][2]);
            cout << "moveHero: " << moveHero('d', map, width, height, heroStatus) << endl;
            printMap(map, width, height);
            printHeroStatus(heroStatus);
            cout << "Hero is " << (heroStatus.alive?"alive":"dead") << endl;
            cout << "Linked list nodes at (0,0): "; printLinkedList(map[0][0]);
            cout << "Linked list nodes at (1,0): "; printLinkedList(map[0][1]);
            cout << "Linked list nodes at (2,0): "; printLinkedList(map[0][2]);
            //for this test case, we deliberately chose not to release the dynamic memory allocated; memory leak won't be checked for this case
        }
        else if(testCaseNumber == 24)
        {
            //description: simple monster encounter (1 weapon, 1 monster)
            int width = 3;  //map width
            int height = 1; //map height
            HeroStatus heroStatus;
            Node ***map = generateMap(width, height);
            addThing(map, width, height, 0, 0, HERO, 1);
            addThing(map, width, height, 1, 0, MACE, 1);
            addThing(map, width, height, 2, 0, SKELETON, 1);
            cout << "moveHero: " << moveHero('d', map, width, height, heroStatus) << endl;
            printMap(map, width, height);
            printHeroStatus(heroStatus);
            cout << "Hero is " << (heroStatus.alive?"alive":"dead") << endl;
            cout << "Linked list nodes at (0,0): "; printLinkedList(map[0][0]);
            cout << "Linked list nodes at (1,0): "; printLinkedList(map[0][1]);
            cout << "Linked list nodes at (2,0): "; printLinkedList(map[0][2]);
            cout << "moveHero: " << moveHero('d', map, width, height, heroStatus) << endl;
            printMap(map, width, height);
            printHeroStatus(heroStatus);
            cout << "Hero is " << (heroStatus.alive?"alive":"dead") << endl;
            cout << "Linked list nodes at (0,0): "; printLinkedList(map[0][0]);
            cout << "Linked list nodes at (1,0): "; printLinkedList(map[0][1]);
            cout << "Linked list nodes at (2,0): "; printLinkedList(map[0][2]);
            //for this test case, we deliberately chose not to release the dynamic memory allocated; memory leak won't be checked for this case
        }
        else if(testCaseNumber == 25)
        {
            //description: simple monster encounter (0 weapon, 1 monster)
            int width = 3;  //map width
            int height = 1; //map height
            HeroStatus heroStatus;
            Node ***map = generateMap(width, height);
            addThing(map, width, height, 0, 0, HERO, 1);
            addThing(map, width, height, 2, 0, SKELETON, 1);
            cout << "moveHero: " << moveHero('d', map, width, height, heroStatus) << endl;
            printMap(map, width, height);
            printHeroStatus(heroStatus);
            cout << "Hero is " << (heroStatus.alive?"alive":"dead") << endl;
            cout << "Linked list nodes at (0,0): "; printLinkedList(map[0][0]);
            cout << "Linked list nodes at (1,0): "; printLinkedList(map[0][1]);
            cout << "Linked list nodes at (2,0): "; printLinkedList(map[0][2]);
            cout << "moveHero: " << moveHero('d', map, width, height, heroStatus) << endl;
            printMap(map, width, height);
            printHeroStatus(heroStatus);
            cout << "Hero is " << (heroStatus.alive?"alive":"dead") << endl;
            cout << "Linked list nodes at (0,0): "; printLinkedList(map[0][0]);
            cout << "Linked list nodes at (1,0): "; printLinkedList(map[0][1]);
            cout << "Linked list nodes at (2,0): "; printLinkedList(map[0][2]);
            //for this test case, we deliberately chose not to release the dynamic memory allocated; memory leak won't be checked for this case
        }
    }

    return 0;
}