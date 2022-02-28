#include <iostream>
#include <vector>
#include <math.h>
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
        cout << "A Square: the sides are " << width << " long." << " Border Shape: "<< shapeBorder << endl;
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
    Rectangle() :Square() { height = 0; };
    Rectangle(int width, int height) :Square(width) { this->height = height; }
    Rectangle(int width, int height, char shapeBorder) :Square(width, shapeBorder) 
    { 
        this->height = height; 
    }
    void describe(ostream& os)
    {
        cout << "A Rectangle: the sides are " << width << " wide and " << height << " high." << " Border Shape: " << shapeBorder << endl;
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
    //different versions of constructor
    IsocTriangle() :Shape() { height = 0; setWidth(); };
    IsocTriangle(int height) :Shape()
    {
        this->height = height;
        setWidth();
    }//if the user wants one with a different char then do this
    IsocTriangle(int height, char shapeBorder)
    {
        this->height = height;
        setWidth();
        this->shapeBorder = shapeBorder;
    }
    //describe that recieves and ostream variable, so it can be called from operator<<
    void describe(ostream& os)
    {
        cout << "A Isosceles Triangle: the its height is "<< height <<" and its base is " << width << " wide." << " Border Shape: " << shapeBorder << endl;
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
                cout << shapeBorder;
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
public:
    Circle() {};
    Circle(int width) :Shape(width) {};
    Circle(int width, char shapeBorder) :Shape(width, shapeBorder) {};
    //overloaded describe that recieves and ostream variable, so it can be called from operator<<
    void describe(ostream& os)
    {
        cout << "A Circle: its diameter is " << width << "." << " Border Shape: " << shapeBorder << endl;
    }
    //plain desribe function, that calls the describe with the ostream
    void describe()
    {
        describe(cout);
    }
    //overloaded draw funcion that has ostream passed in so it can be called from operator<<
    void draw(ostream& os)
    {
        int radius = width / 2;//get radius from width
        
        for (int x = -radius; x <= radius; x++)
        {
            for (int y = -radius; y <= radius; y++)
            {
                int eq = x * x + y * y - radius * radius; //x squared + y squared = r squared is graph equation for a circle
                if (abs(eq) <= radius) //abs() returns the absolute value of a number i.e the number without a sign // if the numebr falls inside the sqrt of theradius then print shape, else print "  "
                {
                    cout << shapeBorder<<" ";
                }
                else
                {
                    cout << "  ";
                }
            }
            cout << endl;
        }
    }
    //plain draw function that calls the draw function with ostream
    void draw()
    {
        draw(cout);
    }

    //+ operator adds to circle together
    Circle operator+(Circle c2)
    {
        Circle newCircle(this->width + c2.width);
        return newCircle;
    }
    //== checked for euqality.
    bool operator==(Circle c2)
    {
        if (this->width == c2.width)
        {
            return true;
        }
        return false;
    }
};
void printShapes(vector<Shape*> shapes)
{
    for (int i = 0; i < shapes.size(); i++)
    {
        cout << (i + 1)<< " ";
        shapes[i]->describe();
    }
}
int main()
{    
    //Implement these classes
    Rectangle r(5,10,'#');
    Rectangle r2(50, 10, '#');
    IsocTriangle it(10,'~');
    IsocTriangle it2(15, '0');
    Circle c(18,'&');
    Circle c2(20, '&');
    Square s(12, '*');
    Square s2(5, '*');
    Square s3(14, '@');
    Circle c3 = c + c2;
     //test out your overloaded operators
     //you could create a menu and the the user to input shapes and border chars
    vector<Shape*> shapes;
    shapes.push_back(&r);
    shapes.push_back(&it);
    shapes.push_back(&c);
    shapes.push_back(&s);
    shapes.push_back(&r2);
    shapes.push_back(&it2);
    shapes.push_back(&c2);
    shapes.push_back(&s2);
    shapes.push_back(&c3);
    shapes.push_back(&s3);
    
    while (true)
    {
        cout << "Welcome to the shape program " << endl;
        cout << "These shapes are available: " << endl << endl;
        printShapes(shapes);
        cout << endl;
        cout << "What shape would you like to display? " << endl;

        int usrInput;
        cin >> usrInput;
        if(usrInput>shapes.size()||usrInput<=0)
        {
            break;
        }
        system("cls");
        cout << shapes[usrInput - 1];
    }    
}

