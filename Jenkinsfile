pipeline {
  agent any 
  stages {
    stage ("build") {
          steps {
            echo "build"
          }

    }
    stage ("run") {
      steps {
        echo "run"
        javac First_java.java
        java First_java
      }
    }
  }
}
           
           
