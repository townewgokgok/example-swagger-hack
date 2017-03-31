<?hh

namespace petstore;

require_once __DIR__ . "/../vendor/autoload.php";

/**
 * @SWG\Definition(required={"id", "name"})
 */
class Pet {

	/**
	 * @SWG\Property(property="id", type="integer", format="int64")
	 */
	public int $id;

	/**
	 * @SWG\Property(property="name")
	 * @var string
	 */
	public string $name;

	/**
	 * @SWG\Property(property="tag")
	 * @var string
	 */
	public string $tag;

	public function __construct() {
		$this->id = 0;
		$this->name = "";
		$this->tag = "";
	}
}
