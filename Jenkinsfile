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
        bat 'javac First_java.java'
        bat 'java First_java'
      }
    }
  }
}
           
           
