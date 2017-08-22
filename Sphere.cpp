#include <iostream>
#include <cmath> // for power function
using namespace std;

const double PI = 3.14159;

// Forward declarations
class Sphere;
ostream &operator << (ostream&, const Sphere&);
istream &operator >> (istream&, Sphere&);

class Sphere {
   private:
      double volume;
      double radius;
   public:
      // Constructors first
      Sphere() {
         volume = 0.0;
         radius = 0.0;
      }
      Sphere(double r) {
         radius = r;
         setVolume(radius);
      }
      // Mutators - for private member variables
      void setRadius(double r);
      void setVolume(double);

      // Next are the accessors -- made them inline member functions
      double getVolume() const {
         return volume;
      }
      double getRadius() const {
         return radius;
      }
      // Friend functions
      friend istream &operator >> (istream&, Sphere&);
      friend ostream &operator << (ostream&, const Sphere&);
};

// overload >> and << operators so i can use cin and cout on a sphere instance
istream &operator >> (istream &stream, Sphere &obj) { 
   cout << "What is the radius?: ";
   stream >> obj.radius;
   obj.setVolume(obj.radius); // call setVolume member function and pass it the radius
   return stream;
}
ostream &operator << (ostream &stream, const Sphere &obj) {
   stream << "Sphere radius is: " << obj.radius << endl;
   stream << "Sphere volume is: " << obj.volume << endl;
   return stream;
}

void Sphere::setVolume (double radius) {
   volume = (4.0 / 3.0 * PI * pow(radius, 3)); // formula given for volume
}

void Sphere::setRadius(double r) {
   radius = r;
}

int main() {

   Sphere user; // create instance
   char ch;
   while (1) { // Creating a loop until user enters y or n
      cin >> user; // set values for user object
      cout << user;  // print values for user object
      cout << "\npress y to continue or n to quit: ";
      while (1) {
         cin >> ch;
         if (ch == 'n' || ch == 'N')
            return 0;
         if (ch == 'y' || ch == 'Y')
            break;
      }
   }

   return 0;
} 
