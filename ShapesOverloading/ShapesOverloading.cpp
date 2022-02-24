#include <iostream>
#include <vector>
using namespace std;

class Shape
{
protected:
    int width;
    char shapeBorder;
public:
    Shape() { width = 0; shapeBorder = '*'; }
    Shape(int width)
    {
        this->width = width;
        this->shapeBorder = '*';
    }
    Shape(int width, char shapeBorder)
    {
        this->width = width;
        this->shapeBorder = shapeBorder;
    }
    //a function to describe the shape. It will say the type of shape and its size;
    virtual void describe() = 0;//HINT!, you could create and overloaded version of this function that receives ostream. this will help with operator<<
    virtual void describe(ostream&) = 0;
                                //draw the shape, a fucntion to draw the shape
    virtual void draw() = 0;//HINT!, you could create and overloaded version of this function that receives ostream. this will help with operator<<
    virtual void draw(ostream&) = 0;
    //Implement:
    //Implement:
    //operator+ to add two shapes of the same type together
    //operator= to check if two shapes are the same.
    //operator<< as an alternative to the draw() function

    friend ostream& operator<<(ostream& os, Shape* s)//if we pass in a square pointer here, we can use this for rectangles as well
    {
        s->describe(os); //thse are overridden in rectangle so will be called correctly
        s->draw(os);
        return os;
    }
    //if you finish, implement other functions you feel could be useful
};
//started you off with square
class Square : public Shape
{
public:
    Square() {};
    Square(int width) :Shape(width) {};
    Square(int width, char shapeBorder) :Shape(width, shapeBorder) {};
    //overloaded describe that recieves and ostream variable, so it can be called from operator<<
    void describe(ostream& os)
    {
        cout << "this is a square the sides are " << width << " long" << endl;
    }
    //plain desribe function, that call the describe with the ostream
    void describe()
    {
        describe(cout);
    }
    //overloaded draw funcion that has ostream passed in so it can be called from operator<<
    void draw(ostream& os)
    {
        for (int i = 0; i < width; i++)
        {
            for (int j = 0; j < width; j++)
            {
                if (i == 0 || i == (width - 1))
                {
                    os << shapeBorder << " ";
                }
                else if (j == 0 || j == (width - 1))
                {
                    os << shapeBorder << " ";
                }
                else
                {
                    os << "  ";
                }
            }
            os << endl;
        }
    }
    //plain draw function that calls the draw function with ostream
    void draw()
    {
        draw(cout);
    }
   
    Square operator+(Square s2)
    {
        Square newSquare(this->width + s2.width);
        return newSquare;
    }
    bool operator==(Square s2)
    {
        if (this->width == s2.width)
        {
            return true;
        }
        return false;
    }
};

class Rectangle :public Square {
private:
    int height;
public:
    Rectangle() { height = 0; };
    Rectangle(int width, int height) :Square(width) { this->height = height; }
    Rectangle(int width, int height, char shapeBorder) :Square(width, shapeBorder) { this->height = height; }
    void describe(ostream& os)
    {
        cout << "this is a rectangle the sides are " << width << " wide and " << height << " high"<< endl;
    }
    //plain desribe function, that call the describe with the ostream
    void describe()
    {
        describe(cout);
    }
    //draw funcion that has ostream passed in so it can be called from operator<<
    void draw(ostream& os)
    {
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                if (i == 0 || i == (height - 1))
                {
                    os << shapeBorder << " ";
                }
                else if (j == 0 || j == (width - 1))
                {
                    os << shapeBorder << " ";
                }
                else
                {
                    os << "  ";
                }
            }
            os << endl;
        }
    }
    //plain draw function that calls the draw function with ostream
    void draw()
    {
        draw(cout);
    }
    Rectangle operator+(Rectangle r2)
    {
        Rectangle newRectangle(this->width + r2.width, this->height+r2.height);
        return newRectangle;
    }
    bool operator==(Rectangle r2)
    {
        if (this->width == r2.width && this->height==r2.height)
        {
            return true;
        }
        return false;
    }
};

class IsocTriangle : public Shape
{
private:
    int height;
    void setWidth()
    {
        width = (height * 2) - 1;        
    }
public:
    IsocTriangle() :Shape() { height = 0; setWidth(); };
    IsocTriangle(int height) :Shape()
    {
        this->height = height;
        setWidth();
    }
    IsocTriangle(int height, char shapeBorder)
    {
        this->height = height;
        setWidth();
        this->shapeBorder = shapeBorder;
    }
    //describe that recieves and ostream variable, so it can be called from operator<<
    void describe(ostream& os)
    {
        cout << "this is a isosceles triangle the its height is "<< height <<" and its base is " << width << " wide "<< endl;
    }
    //plain desribe function, that call the describe with the ostream
    void describe()
    {
        describe(cout);
    }
    //draw funcion that has ostream passed in so it can be called from operator<<
    void draw(ostream& os)
    {
        int space = height;
        for (int i = 0; i < height; i++) {
            for (int j = space; j > 0; j--) {
                cout << " ";
            }
            for (int star = 0; star <= i * 2; star++) {
                cout << "*";
            }
            space--;
            cout << endl;
        }
    }
    //plain draw function that calls the draw function with ostream
    void draw()
    {
        draw(cout);
    }

    IsocTriangle operator+(IsocTriangle it2)
    {
        IsocTriangle newisocTri(this->width + it2.width);
        return newisocTri;
    }

    bool operator==(IsocTriangle r2)
    {
        if (this->width == r2.width)
        {
            return true;
        }
        return false;
    }
};

class Circle : public Shape {

};

int main()
{
    IsocTriangle it(6);
    cout << &it;
    //Implement these classes
    //Rectangle r(5,10,'*');
    //IsocTriangle it(10,20,'*');
    //Circle c(10,'*');
   vector<Shape*> shapes;
    Square s1(5, '*');
    Square s2(10, '*');
    Square s3 = s1 + s2;
    Rectangle r1(10, 5, '#');
    Rectangle r2(8, 14, '#');
    //add more shapes to the vector.
    shapes.push_back(&r2);
    shapes.push_back(&s1);
    shapes.push_back(&s3);
    shapes.push_back(&r1);

    for (int i = 0; i < shapes.size(); i++)
    {
        shapes[i]->describe();
        shapes[i]->draw();
    }
    //test out your overloaded operators
    cout << &s2;
    cout << &r2;

    if (s1 == s2)
    {
        cout << &s1 << &s2;
        cout << "These two shapes are the same " << endl;
    }
    else
    {
        cout << &s1 << &s2;
        cout << "These two shapes are NOT the same " << endl;
    }
}

