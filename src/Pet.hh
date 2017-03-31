<?hh

namespace petstore;

require_once __DIR__ . "/../vendor/autoload.php";

/**
 * @SWG\Definition(required={"id", "name"})
 */
class Pet {

	/**
	 * @SWG\Property(type="integer", format="int64")
	 */
	public int $id;

	/**
	 * @SWG\Property()
	 * @var string
	 */
	public string $name;

	/**
	 * @SWG\Property()
	 * @var string
	 */
	public string $tag;

	public function __construct() {
		$this->id = 0;
		$this->name = "";
		$this->tag = "";
	}
}
