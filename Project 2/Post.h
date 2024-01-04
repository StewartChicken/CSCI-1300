//Post.h

// CSCI 1300 Spring 2023
// Author: Evan Poon
// Recitation: 201 – Kyle Ruvane
// Project2 - Question 1

#ifndef Post_h
#define Post_h
#include <iostream>

//Post class declaration
class Post{

    //Post class data members
    private:
        std::string body_;
        std::string post_author_;
        int num_likes_;
        std::string date_; // mm/dd/yy format

    public:
        
        //Constructors
        Post();
        Post(std::string, std::string, int, std::string); //body, author, likes, date

        //Body encapsulation
        std::string getPostBody();
        void setPostBody(std::string);

        //Author encapsulation
        std::string getPostAuthor();
        void setPostAuthor(std::string);

        //Likes encapsulation
        int getPostLikes();
        void setPostLikes(int);

        //Date encapsulation
        std::string getPostDate();
        void setPostDate(std::string);

};

#endif