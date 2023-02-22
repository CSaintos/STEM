
Set-Variable -Name "includes" -Value "-Iinc\util", "-Iinc\util\error", "-Iinc\util\token", "-Iinc\util\node", "-Iinc\util\node\op_node", "-Iinc\util\node\value_node", "-Iinc\front", "-Iinc\back", "-Iinterface"

echo "clean"
rm build\GeneratorTest.exe

echo "compile"
g++ $includes -c src\util\error\Error.cpp -o bin\Error.o -g
g++ $includes -c src\util\error\IllegalCharError.cpp -o bin\IllegalCharError.o -g
g++ $includes -c src\util\error\SyntaxError.cpp -o bin\SyntaxError.o -g
g++ $includes -c src\util\token\TokenUtils.cpp -o bin\TokenUtils.o -g
g++ $includes -c src\util\token\Token.cpp -o bin\Token.o -g
g++ $includes -c src\util\node\Node.cpp -o bin\Node.o -g
g++ $includes -c src\util\node\op_node\BinOpNode.cpp -o bin\BinOpNode.o -g
g++ $includes -c src\util\node\op_node\UnaOpNode.cpp -o bin\UnaOpNode.o -g
g++ $includes -c src\util\node\value_node\DigitNode.cpp -o bin\DigitNode.o -g
g++ $includes -c src\util\node\value_node\IdentifierNode.cpp -o bin\IdentifierNode.o -g
g++ $includes -c src\front\Reader.cpp -o bin\Reader.o -g
g++ $includes -c src\front\Lexer.cpp -o bin\Lexer.o -g
g++ $includes -c src\front\Parser.cpp -o bin\Parser.o -g
g++ $includes -c src\back\Generator.cpp -o bin\Generator.o -g
g++ $includes -c src\util\PluginLoader.cpp -o bin\PluginLoader.o -g
g++ $includes -c test\back\GeneratorTest.cpp -o bin\GeneratorTest.o -g

echo "build"
g++ bin\*.o -o build\GeneratorTest.exe

echo "obj-clean"
rm bin\*.o