swagger-php で Hack のコードをスキャンできるか実験

```
$ hhvm generate.hh
```

```yaml
swagger: '2.0'
info:
    title: 'Swagger Petstore'
    license:
        name: MIT
    version: 1.0.0
host: petstore.swagger.io
basePath: /v1
schemes:
    - http
consumes:
    - application/json
produces:
    - application/json
paths:
    /pets:
        get:
            tags:
                - pets
            summary: 'List all pets'
            operationId: listPets
            parameters:
                -
                    name: limit
                    in: query
                    description: 'How many items to return at one time (max 100)'
                    required: false
                    type: integer
                    format: int32
            responses:
                200:
                    description: 'An paged array of pets'
                    schema:
                        $ref: '#/definitions/Pets'
                    headers:
                        x-next:
                            description: 'A link to the next page of responses'
                            type: string
                default:
                    description: 'unexpected error'
                    schema:
                        $ref: '#/definitions/Error'
        post:
            tags:
                - pets
            summary: 'Create a pet'
            operationId: createPets
            responses:
                201:
                    description: 'Null response'
                default:
                    description: 'unexpected error'
                    schema:
                        $ref: '#/definitions/Error'
    '/pets/{petId}':
        get:
            tags:
                - pets
            summary: 'Info for a specific pet'
            operationId: showPetById
            parameters:
                -
                    name: petId
                    in: path
                    description: 'The id of the pet to retrieve'
                    required: true
                    type: string
            responses:
                200:
                    description: 'Expected response to a valid request'
                    schema:
                        $ref: '#/definitions/Pets'
                default:
                    description: 'unexpected error'
                    schema:
                        $ref: '#/definitions/Error'
definitions:
    Error:
        required:
            - code
            - message
        properties:
            code:
                type: integer
                format: int32
            message:
                type: string
    Pets:
        type: array
        items:
            $ref: '#/definitions/Pet'
    Pet:
        required:
            - id
            - name
        properties:
            id:
                type: integer
                format: int64
            name:
                type: string
            tag:
                type: string
```

`property` や `type` はコードから自明なので、ちょっと冗長。さすがにここを自動でやるには改造が要る

```hack
/**
 * @SWG\Property(property="id", type="integer", format="int64")
 */
public int $id;
```
