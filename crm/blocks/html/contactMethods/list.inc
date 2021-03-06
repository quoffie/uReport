<?php
/**
 * @copyright 2012-2014 City of Bloomington, Indiana
 * @license http://www.gnu.org/licenses/agpl.txt GNU/AGPL, see LICENSE.txt
 * @author Cliff Ingham <inghamn@bloomington.in.gov>
 */
use Application\Models\ContactMethodTable;
use Application\Models\Person;

use Blossom\Classes\View;
?>
<div>
	<h2><?php
			echo $this->translate(array('labels.contactMethod','labels.contactMethods',2));
			if (Person::isAllowed('contactMethods','update')) {
				$helper = $this->template->getHelper('buttonLink');
				echo $helper->buttonLink(
					BASE_URI.'/contactMethods/update',
					$this->translate('labels.add'),
					'add'
				);
			}
		?>
	</h2>
	<p><?php echo $this->translate('text.contactMethods_description'); ?></p>
	<ul>
	<?php
		$table = new ContactMethodTable();
		$list = $table->find();
 		foreach ($list as $method) {
			if (Person::isAllowed('contactMethods','update')) {
				$editButton = $helper->buttonLink(
					BASE_URI.'/contactMethods/update?contactMethod_id='.$method->getId(),
					$this->translate('labels.edit'),
					'edit'
				);
			}
			$name = View::escape($method->getName());
			echo "<li>$editButton $name</li>";
		}
	?>
	</ul>
</div>
