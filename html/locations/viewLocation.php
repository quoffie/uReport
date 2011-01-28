<?php
/**
 * @copyright 2011 City of Bloomington, Indiana
 * @license http://www.gnu.org/copyleft/gpl.html GNU/GPL, see LICENSE.txt
 * @author Cliff Ingham <inghamn@bloomington.in.gov>
 * @param $_GET location
 */
// Make sure we have the location in the system
$ticketList = new TicketList(array('location'=>$_GET['location']));
if (!count($ticketList)) {
	$url = new URL(BASE_URL.'locations');
	$url->location_query = $_GET['location'];
	header("Location: $url");
	exit();
}

$template = new Template();
$template->blocks[] = new Block('locations/locationPanel.inc',array('location'=>$_GET['location']));
$template->blocks[] = new Block('tickets/ticketList.inc',array('ticketList'=>$ticketList));


echo $template->render();