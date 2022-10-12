// Powered by Infostretch 

timestamps {

node () {

	stage ('Ecommerce-Management-System - Checkout') {
 	 checkout([$class: 'GitSCM', branches: [[name: '*/main']], doGenerateSubmoduleConfigurations: false, extensions: [], submoduleCfg: [], userRemoteConfigs: [[credentialsId: '9d6b7018-81e2-425a-a324-c389e61b8744', url: 'https://github.com/ShibinChristin/Ecommerce-Management-System.git']]]) 
	}
	stage ('Ecommerce-Management-System - Build') {
 	
// Unable to convert a build step referring to "hudson.plugins.ws__cleanup.PreBuildCleanup". Please verify and convert manually if required.		// Shell build step
sh """ 
g++ Ecommerce.cpp Merchant.cpp Customer.cpp Courier.cpp main.cpp 
 """ 
	}
	stage ('Ecommerce-Management-System - Post build actions') {
/*
Please note this is a direct conversion of post-build actions. 
It may not necessarily work/behave in the same way as post-build actions work.
A logic review is suggested.
*/
		// Mailer notification
		step([$class: 'Mailer', notifyEveryUnstableBuild: true, recipients: 'shibinchristin541@gmail.com', sendToIndividuals: false])
 
	}
}
}