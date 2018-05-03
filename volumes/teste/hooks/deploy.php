<?php
	/**
	 * GIT DEPLOYMENT SCRIPT
	 */

	// Commands
	$commands = array(
		'git pull',
		'git submodule sync',
		'git submodule update',
		'git submodule status',
	);
	
	// Run
	foreach($commands AS $command){
		$tmp = shell_exec($command);
	}
?>
