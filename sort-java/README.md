# Quicksort in java

This is part of a project for testing the speed of quicksort between java and c++.
This is the java part.

## Building

This project uses gradle as a build system. Before you start make sure you have the java jdk installed.
The project has originally been build for java 11, but it should work on versions from java 8 onwards.

The following commands are for linux/ macos, but if you are on windows you will need to replace `gradlew` with `gradlew.bat`. 

First make sure you're in the `sort-java` folder

```bash
cd sort-java
```

Now run the `jar` task in gradle

```bash
./gradlew jar
```

This will generate a jar in the `build/libs` folder.

## Running the test

To run the test make sure the pc is not busy with other work to give the test the best possible scenario.

To run the test just run the jar file with java.

```bash
java -jar ./build/libs/sort-1.0-SNAPSHOT.jar
```

Now wait for the tests to finish, there should be a percentage in the terminal for the current test.

After the tests are done there should be a few csv files with the test results.
