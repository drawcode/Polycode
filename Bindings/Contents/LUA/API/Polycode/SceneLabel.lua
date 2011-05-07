require "Polycode/SceneEntity"

class "SceneLabel" (SceneEntity)







function SceneLabel:SceneLabel(...)
	for k,v in pairs(arg) do
		if type(v) == "table" then
			if v.__ptr ~= nil then
				arg[k] = v.__ptr
			end
		end
	end
	if self.__ptr == nil and arg[1] ~= "__skip_ptr__" then
		self.__ptr = Polycore.SceneLabel(unpack(arg))
		Polycore.__ptr_lookup[self.__ptr] = self
	end
end

function SceneLabel:testMouseCollision(x, y)
	local retVal = Polycore.SceneLabel_testMouseCollision(self.__ptr, x, y)
	return retVal
end

function SceneLabel:setText(newText)
	local retVal = Polycore.SceneLabel_setText(self.__ptr, newText)
end

function SceneLabel:getLabel()
	local retVal =  Polycore.SceneLabel_getLabel(self.__ptr)
	if Polycore.__ptr_lookup[retVal] ~= nil then
		return Polycore.__ptr_lookup[retVal]
	else
		Polycore.__ptr_lookup[retVal] = Label("__skip_ptr__")
		Polycore.__ptr_lookup[retVal].__ptr = retVal
		return Polycore.__ptr_lookup[retVal]
	end
end

function SceneLabel:Render()
	local retVal =  Polycore.SceneLabel_Render(self.__ptr)
end

