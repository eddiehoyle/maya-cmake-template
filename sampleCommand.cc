
#include <maya/MString.h>
#include <maya/MGlobal.h>
#include <maya/MSimple.h>

DeclareSimpleCommand( helloWorld, "Autodesk", "2016");

MStatus helloWorld::doIt( const MArgList& ) {
    MString msg = "Hello, world!";
    MGlobal::displayInfo( msg );
    return MS::kSuccess;
}