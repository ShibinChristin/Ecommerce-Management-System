pipeline{
  agent{
  label 'win_10'
  }
  stages{
      stage('Download Build Wrapper') {
        steps{
    powershell '''
      $path = "$HOME/.sonar/build-wrapper-win-x86.zip"
      rm build-wrapper-win-x86 -Recurse -Force -ErrorAction SilentlyContinue
      rm $path -Force -ErrorAction SilentlyContinue
      mkdir $HOME/.sonar
      [Net.ServicePointManager]::SecurityProtocol = [Net.SecurityProtocolType]::Tls12
      (New-Object System.Net.WebClient).DownloadFile(http://192.168.1.82:9000//static/cpp/build-wrapper-win-x86.zip", $path)
      Add-Type -AssemblyName System.IO.Compression.FileSystem
      [System.IO.Compression.ZipFile]::ExtractToDirectory($path, "$HOME/.sonar")
    '''
  }
      }
  stage('Build') {
    steps{
    powershell '''
      $env:Path += ";$HOME/.sonar/build-wrapper-win-x86"
      build-wrapper-win-x86-64 --out-dir bw-output <your clean build command>
    '''
  }
  }
  stage('SonarQube Analysis') {
    steps{
      script{
    def scannerHome = tool 'SonarScanner';
    withSonarQubeEnv() {
      powershell "${scannerHome}/bin/sonar-scanner -Dsonar.cfamily.build-wrapper-output=bw-output"
    }
      }
    }
  }
}
  
  }
