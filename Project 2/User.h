//User.h

// CSCI 1300 Spring 2023
// Author: Evan Poon
// Recitation: 201 – Kyle Ruvane
// Project2 - Question 4

#include <iostream>

#ifndef User_h
#define User_h

class User{

    private:

        std::string username_;

        //num posts available
        int num_posts_;

        static const int size_ = 50;

        // -1 means user hasn't viewed post
        //  0 means user hasn't liked the post
        //  max of 10 likes per post
        int likes_[size_]; 

    public:

        //Constructors
        User();
        User(std::string, int[], int);

        //Encapsulation
        std::string getUsername();
        void setUsername(std::string);

        int getLikesAt(int); //returns -2 if argument is > size of likes_ array or < 0

        //index, likes
        bool setLikesAt(int, int); //likes must be btwn -1 and 10. index must be within
                                   //bounds of likes_ array. Returns true if post updated

        int getNumPosts();
        void setNumPosts(int);

        int getSize();

};

#endif