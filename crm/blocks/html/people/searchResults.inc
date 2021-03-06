<?php
/**
 * @copyright 2011-2014 City of Bloomington, Indiana
 * @license http://www.gnu.org/licenses/agpl.txt GNU/AGPL, see LICENSE.txt
 * @author Cliff Ingham <inghamn@bloomington.in.gov>
 * @param PersonList $this->personList
 * @param bool $this->disableButtons
 */
use Application\Models\Person;
use Blossom\Classes\Url;
?>
<div class="findPeopleResults">
	<h2><?php echo $this->translate('labels.search_results'); ?></h2>
	<?php
		if (count($this->personList)) {
			include APPLICATION_HOME.'/blocks/html/people/personList.inc';
		}
		else {
			echo '<p>No results found</p>';
		}
		if (!$this->disableButtons && Person::isAllowed('people','add')) {
			include APPLICATION_HOME.'/blocks/html/people/personSelectForMerge.inc';


			// Preserve any extra parameters passed in
			$url = new Url(BASE_URL.'/people/update');
			$fields = array('firstname','lastname','email','organization','setOfPeople');
			foreach ($_REQUEST as $key=>$value) {
				if (!in_array($key,$fields)) {
					$url->$key = $value;
				}
			}
			$h = $this->template->getHelper('buttonLink');
			echo $h->buttonLink(
				$url,
				$this->translate('labels.add_person'),
				'add'
			);
		}
	?>
</div>
