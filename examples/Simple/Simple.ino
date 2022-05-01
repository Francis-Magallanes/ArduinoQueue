/**
 * @file Simple.ino
 * @author Francis John N. Magallanes
 * @brief This .ino file shows the a simple usage of the queue
 * class which only involves enqueue(), dequeue(), and isEmpty() method
 * of the queue object.
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <Queue.h>

/**
 * @brief A simple class that describes a person through a class. 
 * 
 */
class Person
{
public:

    Person()
    {

    }

    Person(String firstName, String lastName, uint8_t age) 
        : FirstName(firstName), LastName(lastName), Age(age)
    {

    }

    bool operator == (const c_Person &anotherPerson)
    {
        return (this->FirstName == anotherPerson.FirstName) &&
                (this->LastName == anotherPerson.LastName) &&
                (this->Age == anotherPerson.Age);
    }

private:
    String FirstName;
    String LastName;
    uint8_t Age;
};

// declare a queue object whoise max size is 10 Person objects
Queue<Person, 10> queueing;

Person person1 ("FirstNamePerson1","LastNamePerson1",27);
Person person2 ("FirstNamePerson2","LastNamePerson2",22);
Person person3 ("FirstNamePerson3","LastNamePerson3",23);
Person person4 ("FirstNamePerson4","LastNamePerson4",24);
Person person5 ("FirstNamePerson5","LastNamePerson5",25);

void setup()
{
    // enqueue the person objects
    queueing.enqueue(person1);
    queueing.enqueue(person2);
    queueing.enqueue(person3);
    queueing.enqueue(person4);
    queueing.enqueue(person5);    
}

void loop()
{
    static unsigned long m = millis();

    //every 1 second,one person object is dequeued until it is not empty
    if(millis() - m >= 6000 && !queueing.isEmpty())
    {
        queueing.dequeue();
        m = millis();
    }
}