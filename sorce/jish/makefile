

main:
	$(MAKE) clean
	javac Julia.java
	echo "Manifest-Version: 1.0\nMain-Class: Julia\n\n" > manifest.mf
	jar cmf manifest.mf jish.jar *.class
	mv jish.jar ../../
	$(MAKE) clean

clean:
	-@rm -rf *.*~ makefile~  *.class

