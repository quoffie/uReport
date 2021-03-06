<?php
/**
 * @copyright 2013 City of Bloomington, Indiana
 * @license http://www.gnu.org/licenses/agpl.txt GNU/AGPL, see LICENSE.txt
 * @author Cliff Ingham <inghamn@bloomington.in.gov>
 * @param Address $this->address
 */
use Application\Models\Address;
use Blossom\Classes\View;

$fields = array(
	'address','city','state','zip'
);
foreach ($fields as $field) {
	$get = 'get'.ucfirst($field);
	$$field = View::escape($this->address->$get());
}
?>
<div class="updateAddressForm">
	<form method="post">
		<fieldset><legend><?php echo $this->translate(array('labels.address', 'labels.addresses', 1)); ?></legend>
			<table>
				<tr><td><label for="label"><?php echo $this->translate(array('labels.label', 'labels.labels', 1)); ?></label></td>
					<td><select name="label" id="label">
						<?php
							foreach (Address::$LABELS as $label) {
								$selected = $this->address->getLabel()==$label
									? 'selected="selected"'
									: '';
								echo "<option $selected>$label</option>";
							}
						?>
						</select>
					</td>
				</tr>
				<tr><td><label for="address"><?php echo $this->translate(array('labels.address', 'labels.addresses', 1)); ?></label></td>
					<td><input name="address" id="address" value="<?php echo $address; ?>" /></td>
				</tr>

				<tr><td><label for="city"><?php echo $this->translate('labels.city'); ?></label></td>
					<td><input name="city" id="city" value="<?php echo $city; ?>" /></td>
				</tr>

				<tr><td><label for="state"><?php echo $this->translate('labels.state'); ?></label></td>
					<td><input name="state" id="state" size="2" maxlength="2" value="<?php echo $state; ?>" />
					</td>
				</tr>

				<tr><td><label for="zip"><?php echo $this->translate('labels.zip'); ?></label></td>
					<td><input name="zip" id="zip" size="5" maxlength="5" value="<?php echo $zip; ?>" />
					</td>
				</tr>
			</table>
		</fieldset>
		<fieldset>
			<?php
				if ($this->address->getId()) {
					echo "<input type=\"hidden\" name=\"address_id\" value=\"{$this->address->getId()}\" />";
				}
				else {
					echo "<input type=\"hidden\" name=\"person_id\" value=\"{$this->address->getPerson_id()}\" />";
				}
				$cancelUrl = $this->template->controller == 'AccountController'
					? BASE_URI.'/account'
					: $this->address->getPerson()->getUrl();

				$helper = $this->template->getHelper('saveAndCancelButtons');
				echo $helper->saveAndCancelButtons($cancelUrl);
			?>
		</fieldset>
	</form>
</div>
