<?php
/**
 * @copyright 2011 City of Bloomington, Indiana
 * @license http://www.gnu.org/licenses/agpl.txt GNU/AGPL, see LICENSE.txt
 * @author Cliff Ingham <inghamn@bloomington.in.gov>
 * @param $_GET location
 */
// Make sure we have the location in the system
$location = trim($_GET['location']);
if (!$location) {
	header('Location: '.BASE_URL.'/locations');
	exit();
}
$ticketList = new TicketList(array('location'=>$location));

$template = new Template('locations');
$template->blocks['location-panel'][] = new Block(
	'locations/locationInfo.inc',array('location'=>$location,'disableButtons'=>false)
);
$template->blocks['location-panel'][] = new Block(
	'tickets/ticketList.inc',
	array(
		'ticketList'=>$ticketList,
		'title'=>'Cases Associated with this Location'
	)
);

echo $template->render();
