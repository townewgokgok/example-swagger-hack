<?hh

ini_set("display_errors", "stderr");
require_once "vendor/autoload.php";

use Symfony\Component\Yaml\Yaml;
use Symfony\Component\Finder\Finder;

$finder = (new Finder())
	->sortByName()
	->in(__DIR__ . "/src")
	->name("*.hh");
$swagger = \Swagger\scan($finder);
$json = $swagger->__toString();
echo Yaml::dump(json_decode($json, true), 99);
