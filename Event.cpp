// Author: Camby Abell
// Init date: 07.02.2019
// Last Updates: 07.02.2019

// Event object containing three (!!) fields:
// String eventName -> the name of the event
// String eventDate -> the date the event will occur
// String eventTime -> the time the event will occur

using namespace std;

class Event
{
	private:
		String eventName;
		String eventDate;
		String eventTime;
		// int priority;
			// priority order 1, 2, 3
};

// Default Constructor
Event::Event()
{
	eventName = "";
	eventDate = "";
	eventTime = "";
	// priority = 1;
}

// Paramertized Constructor
Event::Event(String name, String date, String time) //int pri
{
	eventName = name;
	eventDate = date;
	eventTime = time;
	// priority = pri;
}

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// Default Destructor
Event::~Event()
{

}
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// Get Event Name
String Event::getEventName()
{
	return eventName;
}

// Get Event Date
String Event::getEventDate()
{
	return eventDate;
}

// Get Event Time
String Event::getEventTime()
{
	return eventTime;
}

/*
Get Priority
int Event::getPriority()
{
	return priority;
}
*/

// Sets the Event Name
void Event::setEventName(String name)
{
	eventName = name;
}

// Sets the Event Date
void Event::setEventDate(String date)
{
	eventDate = date;
}

// Sets the Event Time
void Event::setEventTime(String time)
{
	eventTime = time;
}

/*
// Sets the priority
void Event::setEventPriority(int pri)
{
	priority = pri
}
*/
