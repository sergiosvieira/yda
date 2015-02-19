#ifndef __YOBJECT_MANAGER__
#define __YOBJECT_MANAGER__

/** YDA **/
#include 

/** STL **/
#include <vector>

/** Forwarding **/
class YObject;

/*!
  This class is used to manager the objects of the game (deallocation, z-order etc)
*/
class YObjectManager
{
public:
	typedef std::vector<YObject*> VectorYObjectPointer;
	//! Default constructor
	YObjectManager();
	//! Default destructor
	~YObjectManager();
	//! Adds a object to manager
	/*!
	  \param YObject - Game object pointer
	*/
	void add(YObject* a_object);
	//! Remove a object from manager
	/*!
	  \param YObject - Game object pointer
	*/
	void remove(YObject* a_object);
	//! Get object pointer at index
	YObject* operator[](int a_index) const
	{
		return m_objects.at(a_index);
	}
	//! Starting to update and render game objects
	void start();
protected:
	int m_size; //! amount of objects
	VectorYObjectPointer m_objects;//! Vector of YObject pointers	
	YMain::FunctionUpdate m_update;//! Function update
	YMain::FunctionRender m_render;//! Function render
private:
	bool m_started;//! Stating update and render flag
};

#endif /** __YOBJECT_MANAGER__ **/