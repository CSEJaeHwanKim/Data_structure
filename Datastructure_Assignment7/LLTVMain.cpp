#include <stdio.h>
#include "TVList.h"
#include "TVNode.h"

void main()
{
	
	CTVList list;

	list.AddHead( new CTVNode( "KBS1", 9, "http://kbs.com" ) );
	list.AddHead(  new CTVNode	( "KBS2", 7 ));
	list.AddHead( new CTVNode ( "MBC", 11 ) );
	list.AddHead( new CTVNode	( "SBS", 5 ) );
	list.Display();

	list.Delete(2);
	list.Add( 2,new CTVNode("KBS3",3) );
	list.Display();
	list.Replace(2,"KBS5",8,"http://kbs.com");
	list.AddTail();
	list.FindName("SBS");
	list.Clear();
	list.Display();
}
