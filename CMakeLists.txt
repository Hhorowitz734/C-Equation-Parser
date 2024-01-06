cmake_minimum_required(VERSION 3.10)
project(EquationParser)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

# Include directories for Raylib
include_directories(/opt/homebrew/Cellar/raylib/4.5.0/include)

# Link directories for Raylib
link_directories(/opt/homebrew/Cellar/raylib/4.5.0/lib)

# Build the main application
add_executable(equationparser main.c src/lexer.c src/parser.c src/visualizer.c)

# Link the Raylib library with your main application
target_link_libraries(equationparser raylib)

# Enable testing with CTest
enable_testing()

# Add an executable for each test
add_executable(lexer_test tests/lexerTest.c src/lexer.c)
add_executable(stack_test tests/stackTest.c utils/stack.c src/lexer.c)
add_executable(queue_test tests/queueTest.c utils/queue.c src/lexer.c)
add_executable(parser_test tests/parserTest.c src/lexer.c src/parser.c)

# Link the test executable with necessary libraries
target_link_libraries(lexer_test cunit)
target_link_libraries(stack_test cunit)
target_link_libraries(queue_test cunit)
target_link_libraries(parser_test cunit)

# Add the test executable to CTest
add_test(NAME LexerTest COMMAND lexer_test)
add_test(NAME StackTest COMMAND stack_test)
add_test(NAME QueueTest COMMAND queue_test)
add_test(NAME ParserTest COMMAND parser_test)

# Set up include directories for the main application and tests
target_include_directories(equationparser PUBLIC /opt/homebrew/opt/cunit/include)
target_include_directories(lexer_test PUBLIC /opt/homebrew/opt/cunit/include)
target_include_directories(stack_test PUBLIC /opt/homebrew/opt/cunit/include)
target_include_directories(queue_test PUBLIC /opt/homebrew/opt/cunit/include)
target_include_directories(parser_test PUBLIC /opt/homebrew/opt/cunit/include)

# Set up library directories for the main application and tests
target_link_directories(equationparser PUBLIC /opt/homebrew/opt/cunit/lib)
target_link_directories(lexer_test PUBLIC /opt/homebrew/opt/cunit/lib)
target_link_directories(stack_test PUBLIC /opt/homebrew/opt/cunit/lib)
target_link_directories(queue_test PUBLIC /opt/homebrew/opt/cunit/lib)
target_link_directories(parser_test PUBLIC /opt/homebrew/opt/cunit/lib)
