..\BDD\sw-bdd\venv\Scripts\Python.exe ..\BDD\sw-bdd\GherkinTools\gherkin2cpp --features-dir=Tests\Specifications --steps-dir=Tests\Steps --cpp -o=Tests\Test.h

..\BDD\sw-bdd\venv\Scripts\Python.exe ..\BDD\fw-cxxtest\bin\cxxtestgen --runner=ErrorFormatter -o Tests/runner.cpp Tests/Test.h
pause