#include <iostream>

import ModulesIntro.ModuleOne;

int main()
{
	std::cout << "Hello, World!" << std::endl;
	Hello::hello();

	std::cout << Hello::add(1.0f, 2.5f) << std::endl;

	return 0;
}

/*
 * #include <QLibrary>
#include <QDebug>

typedef void (*HelloFunction)();

int main() {
    QLibrary library("ModuleOne");

    if (!library.load()) {
        qDebug() << "Could not load the library!";
        return 1;
    }

    HelloFunction hello = (HelloFunction) library.resolve("hello");
    if (!hello) {
        qDebug() << "Could not locate the function!";
        return 1;
    }

    hello();

    library.unload();
    return 0;
}
 */
