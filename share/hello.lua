print("I'm a Lua Script")
print("Loading dynamic library")
package.loadlib("Demo.app/Contents/MacOS/libhello.dylib", "init")()
--package.loadlib("/Users/michael/Documents/src/beleza/build.macosx/Debug/Demo.app/Contents/MacOS/libhello.dylib", "init")()
--package.loadlib("Demo.app/Contents/MacOS/libhello.dylib", "init")()
--package.loadlib("./libhello.so", "init")()
--package.loadlib("./hello.dll", "init")()
--package.loadlib("./libhello.dll", "init")()
greet()
