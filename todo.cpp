//ONLY SUBMIT THIS FILE TO ZINC
#include "given.h"
#include "todo.h"
#include <iostream>
using namespace std;
//be reminded that you should NOT include any additional library, please read "Additional Notes" on the PA3 webpage 

Node*** generateMap(int width, int height)
{
    Node ***map = new Node **[height];
    for (int i = 0; i < height; i++)
    {
        map[i] = new Node *[width];
        for (int j = 0; j < width; j++)
        {
            map[i][j] = nullptr;
        }
    }

    return map;
}

void printHeroStatus(const HeroStatus& heroStatus)
{
    cout<< "Hero status: ";
    cout<< "x=" << heroStatus.x << " ";
    cout<< "y=" << heroStatus.y << " ";
    cout<< "#mace=" << heroStatus.maceCount << " ";
    cout<< "#dagger=" << heroStatus.daggerCount << " ";
    cout<< "#sword=" << heroStatus.swordCount << endl;
}

void printMonsterCount(Node*** map, int width, int height)
{
    if (getMonsterCount(map,width,height)==1)
    {
        cout<<"There is still one more monster left!"<<endl;
    }
    else
    {
        cout << "There are " << getMonsterCount(map, width, height) << " monsters left in the world!" << endl;
    }
}

int getLinkedListLength(const Node* head)
{
    if (head == nullptr)
    {
        return 0;
    }
    else
    {
        int position = 0;
        for (const Node*p = head; p!= nullptr; p=p->next)
        {
            position++;
        }
        return position;
    }
}

bool addThing(Node*** map, int width, int height, int x, int y, Thing thing, int quantity)
{
    if (x >= width || x < 0 || y >= height || y < 0)                //specified position validation
    {
        return false;
    }
    else
    {
        if (map[y][x] == nullptr)
        {
            map[y][x] = new Node;
            map[y][x]->thing = thing;
            map[y][x]->quantity = quantity;
        }
        else
        {
            for (Node* p = map[y][x]; p != nullptr ; p = p->next)
            {
                if (p -> thing == thing)
                {
                    p->quantity += quantity;
                    return true;
                }   
            }
            //if you see this line of code, the thing is not currently in the linked list
            Node* p = map[y][x];
            for (p; p->next != nullptr ; p = p->next);
            p->next = new Node;
            p->next->thing = thing;
            p->next->quantity = quantity;
            p->next->next = nullptr;
            return true;
        }
        
    }
    return true;
}

bool removeThing(Node*** map, int width, int height, int x, int y, Thing thing, int quantity)
{
    if (x >= width || x < 0 || y >= height || y < 0)                //specified position validation
    {
        return false;
    }    
    else
    {
        Node *p = map[y][x];
        Node *prev = nullptr;
        while ( p!= nullptr && p->thing != thing)
        {
            prev = p;
            p = p->next;
        }
        if (p == nullptr || p->quantity < quantity)
        {
            return false;
        }
        else
        {
            if (p->quantity > quantity)
            {
                p->quantity -= quantity;
                return true;
            }
            else 
            {
                if (prev == nullptr)
                {
                    map[y][x]= p-> next;
                }
                else
                {
                    prev->next = p->next;
                }
                delete p;
                return true;
            }   
        }
    }
}

void deleteLinkedList(Node*& head)
{
    if (head == nullptr)
    {
        return;
    }
    deleteLinkedList(head->next);
    delete head;
    head = nullptr;
}

void deleteMap(Node*** map, int width, int height)
{
    for (int y=0; y < height; y++)                
    {
        for (int x=0; x < width; x++)               
        {
            deleteLinkedList(map[y][x]);
        }
        delete []map[y];
        map[y] = nullptr;
    }
    delete []map;
    map = nullptr;
}

bool moveHero(char move, Node*** map, int width, int height, HeroStatus &heroStatus)
{
    int &xloc = heroStatus.x;
    int &yloc = heroStatus.y;              //update hero to original location

    if (move == 'w')
    {
        if (yloc==0)
        {
            return false;
        }
        else
        {
            removeThing(map,width,height,xloc,yloc,HERO,1);
            map[yloc][xloc]=nullptr;
            yloc -=1;
        }
        
    }
    if (move == 's')
    {
        if (yloc == height-1)
        {
            return false;
        }
        else
        {
            removeThing(map,width,height,xloc,yloc,HERO,1);
            map[yloc][xloc]=nullptr;
            yloc +=1;
        }
        
    }
    if (move == 'a')
    {
        if (xloc == 0)
        {
            return false;
        }
        else
        {
            removeThing(map,width,height,xloc,yloc,HERO,1);
            map[yloc][xloc]=nullptr;
            xloc -=1;
        }
        
    }
    if (move == 'd')
    {
        if (xloc == width-1)
        {
            return false;
        }
        else
        {
            removeThing(map,width,height,xloc,yloc,HERO,1);
            map[yloc][xloc]=nullptr;
            xloc +=1;
        }
        
    }

    bool mace,dagger,sword,skeleton,vampire,dragon = false;
    int  Num_mace,Num_dagger,Num_sword,Num_skeleton,Num_vampire,Num_dragon = 0;


    if (map[yloc][xloc]!=nullptr)
    {
        for (Node *p=map[yloc][xloc]; p !=nullptr; p=p->next)
        {
            if (p->thing == MACE)
            {
                mace = true;
                Num_mace = p->quantity;
            }
            else if(p->thing == DAGGER)
            {
                dagger = true;
                Num_dagger = p->quantity;
            }
            else if(p->thing == SWORD)
            {
                sword = true;
                Num_sword = p->quantity;
            }
            else if(p->thing == SKELETON)
            {
                if (heroStatus.maceCount >= p->quantity)
                {
                    skeleton = true;
                    Num_skeleton = p-> quantity;
                }
                else
                {
                    heroStatus.alive = false;
                    return true;
                }
            }
            else if(p->thing == VAMPIRE)
            {
                if (heroStatus.daggerCount >= p->quantity)
                {
                    vampire = true;
                    Num_vampire = p-> quantity;
                }
                else
                {
                    heroStatus.alive = false;
                    return true;
                }
            }
            else if (p->thing == DRAGON)
            {
                if (heroStatus.swordCount >= p->quantity)
                {
                    dragon = true;
                    Num_dragon = p-> quantity;
                }
                else
                {
                    heroStatus.alive = false;
                    return true;
                }
            }
            
        }
        
    }
    // hero survives
    if (mace)
    {
        heroStatus.maceCount += Num_mace;
        removeThing(map, width, height, xloc, yloc, MACE, Num_mace);
    }
    if (dagger)
    {
        heroStatus.daggerCount += Num_dagger;
        removeThing(map, width, height, xloc, yloc, DAGGER, Num_dagger);
    }
    if (sword)
    {
        heroStatus.swordCount += Num_sword;
        removeThing(map, width, height, xloc, yloc, SWORD, Num_sword);
    }

    if (skeleton)
    {
        heroStatus.maceCount -= Num_skeleton;
        removeThing(map, width, height, xloc, yloc, SKELETON, Num_skeleton);
    }

    if (vampire)
    {
        heroStatus.daggerCount -= Num_vampire;
        removeThing(map, width, height, xloc, yloc, VAMPIRE, Num_vampire);
    }
    if (dragon)
    {
        heroStatus.swordCount -= Num_dragon;
        removeThing(map, width, height, xloc, yloc, DRAGON, Num_dragon);
    }   

    addThing(map,width,height,xloc,yloc,HERO,1); 
    return true;
}

int getMonsterCount(Node*** map, int width, int height)
{
    int number = 0;
    for (int y=0; y < height; y++)
    {
        for (int x=0; x < width; x++)
        {
            for ( Node* p =map[y][x]; p != nullptr; p = p->next)
            {
                if (p->thing == SKELETON || p->thing == VAMPIRE || p->thing == DRAGON)
                {
                    number += p->quantity;
                }
                
            }
            
        }
        
    }
    return number;
}
